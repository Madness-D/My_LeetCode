/* ************************************************************************
> File Name:		139单词拆分.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-21 16:11:18
> Link:		https://leetcode.cn/problems/word-break/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//回溯超时了
    bool wordBreak(string s, vector<string>& wordDict) {
        //动态规划
        int len=s.size();
        vector<bool> dp(len+1,false);
        //dp[i]==true 条件： dp[j-1] true && s.substr(j,i-j)在wordDict中
        unordered_set<string> strset;
        for(auto str:wordDict){
            strset.insert(str);
        }

        dp[0]=true;
        for(int i=1;i<=len;i++){
            for(int j=0 ;j<i;j++){
                if(dp[j] && strset.count(s.substr(j,i-j)))
                    dp[i]=true;
            }
        }
        return dp[len];
    }
};