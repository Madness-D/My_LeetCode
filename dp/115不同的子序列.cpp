/* ************************************************************************
> File Name:		115不同的子序列.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-26 15:39:35
> Link:		https://leetcode.cn/problems/distinct-subsequences/
> Description:		给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int l1=s.size(),l2=t.size();

        //答案符号32位，但中间可能溢出，而且long long也可能溢出

        //dp[i][j] 表示s[0:i-1]中出现t[0:j-1]的次数
        vector<vector<unsigned long long>> dp(l1+1,vector<unsigned long long>(l2+1,0));
        //j==0,则认为是出现了1次 i==0则出现0次
        for(int i=0;i<=l1;i++) dp[i][0]=1;
        
        //递推公式？  
        //如果s[i-1]==t[i-1]   dp[i][j]=dp[i-1][j-1]+dp[i-1][j]
        //如果不相等，则dp[i][j]=dp[i-1][j]
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[l1][l2];
    }
};