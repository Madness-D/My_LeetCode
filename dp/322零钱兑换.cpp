/* ************************************************************************
> File Name:		322零钱兑换.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-20 21:37:31
> Link:		https://leetcode.cn/problems/coin-change/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //dp[i]表示金额i需要的最少金币数
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        //先遍历金币和amount都可以
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX) dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];

    }
};