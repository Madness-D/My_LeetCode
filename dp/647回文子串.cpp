/* ************************************************************************
> File Name:		647回文子串.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-26 17:16:22
> Link:		https://leetcode.cn/problems/palindromic-substrings/
> Description:		统计并返回这个字符串中 回文子串 的数目
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        //dp[i][j]表示s[i:j]是否为回文子串
        //如果是，ans++;
        int len=s.size();
        vector<vector<bool>> dp(len,vector<bool>(len,0));
        //for(int i=0;i<len;i++) dp[i][i]=1;
        int ans=0;
        for(int i=len-1;i>=0;i--){
            for(int j=i;j<len;j++){
                if(s[i]==s[j]){
                    if(j==i || j==i+1) {
                        ans++;
                        dp[i][j]=true;
                    }else if(dp[i+1][j-1]){
                        ans++;
                        dp[i][j]=true;
                    }
                }
            }
        }
        return ans;

    }
};