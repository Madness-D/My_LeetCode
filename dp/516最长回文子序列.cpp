/* ************************************************************************
> File Name:		516最长回文子序列.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-26 17:26:37
> Link:		https://leetcode.cn/problems/longest-palindromic-subsequence/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len=s.size();
        vector<vector<int>> dp(len,vector<int>(len,0));
        //dp[i][j]表示 s[i:j]的最长回文子序列的长度
        //边界： i==j 1
        // s[i]==s[j] dp[i][j]=2+dp[i+1][j-1]
        //否则 max(dp[i+1][j],dp[i][j-1])
        int ans=1;
        for(int i=0;i<len;i++) dp[i][i]=1;
        for(int i=len-1;i>=0;i--){
            for(int j=i+1;j<len;j++){
                if(s[i]==s[j]){
                    if(j==i+1) dp[i][j]=2;
                    else dp[i][j]=2+dp[i+1][j-1];
                }else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};