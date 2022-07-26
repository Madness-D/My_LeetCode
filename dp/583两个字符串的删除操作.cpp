/* ************************************************************************
> File Name:		583两个字符串的删除操作.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-26 10:32:09
> Link:		https://leetcode.cn/problems/delete-operation-for-two-strings/
> Description:		返回使两个字符串相等的最小步数，每一步可以删除一个字符串中的一个字符
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string s, string t) {
        int l1=s.size(),l2=t.size();
        //dp[i][j] 表示到s[i-1]和t[j-1]的最小删除步数
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));

        for(int i=1;i<=l1;i++) dp[i][0]=i;
        for(int i=1;i<=l2;i++) dp[0][i]=i;

        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=min(min(dp[i-1][j],dp[i][j-1])+1,dp[i-1][j-1]+2);
                }
            }
        }

        return dp[l1][l2];

    }
};