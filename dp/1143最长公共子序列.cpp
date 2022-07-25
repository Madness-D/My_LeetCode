/* ************************************************************************
> File Name:		1143最长公共子序列.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-25 15:06:15
> Link:		https://leetcode.cn/problems/longest-common-subsequence/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //dp[i][j]表示，到i-1和到j-1的两个字符串的LCS长度（不一定以i和j结尾）
        //如果是到i和j，对于0的处理比较繁琐
        int n1=text1.size(),n2=text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
       // dp[0][0]=text1[0]==text2[0]?1:0;

        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(text1[i]==text2[j]) dp[i+1][j+1]=1+dp[i][j];
                //注意这里的递推公式
                else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }

        return dp[n1][n2];

    }
};