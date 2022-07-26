/* ************************************************************************
> File Name:		72编辑距离.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-26 16:33:06
> Link:		https://leetcode.cn/problems/edit-distance/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string s, string t) {
        //动态规划
        //dp[i][j]表示s[0:i-1] t[0:j-1]的编辑距离
        //边界，dp[i][0]=i dp[0][j]=j  只需要增加或者删除即可
        //递推， 如果s[i-1]==t[j-1] 则dp[i][j]=dp[i-1][j-1]
        //如果不等，则 dp[i][j]=
                    //删除： s删除或t删除 1+min(dp[i-1][j],dp[i][j-1])
                    //替换:  1+dp[i-1][j-1]
                    //插入:  s删除==t插入  s插入==t删除
        int len1=s.size(),len2=t.size();

        if(len1*len2==0) return max(len1,len2);

        vector<vector<int>> dp(len1+1,vector<int>(len2+1));

        for(int i=0;i<=len1;i++) dp[i][0]=i;
        for(int j=0;j<=len2;j++) dp[0][j]=j;
        
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(dp[i-1][j-1]+1,min(dp[i][j-1]+1,dp[i-1][j]+1));
            }
        }
        return dp[len1][len2];

    }
};