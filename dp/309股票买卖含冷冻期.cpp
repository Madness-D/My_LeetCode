/* ************************************************************************
> File Name:		309股票买卖含冷冻期.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-25 13:34:45
> Link:		https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //不能卖出后在第二天就买入
        //dp[i][j] 第i天状态为j下的最大金额
        //j：  没有买入股票0  买入股票(持有股票)1  今日卖出股票2 处于冷冻期3  卖出股票已经超过两天4
        //状态转移
        int len=prices.size();
        if(len==0) return 0;
        //其实0这个状态可以删除
        vector<vector<int>> dp(len,vector<int>(5,0));
        dp[0][1]=-prices[0];
        for(int i=1;i<len;i++){
            //买入股票：没持有买入，已经不在冷冻期买入，之前已经买入, 前一天是冷冻期今天买入
            dp[i][1]=max(max(max(dp[i-1][0],dp[i-1][4]),dp[i-1][3])-prices[i],dp[i-1][1]);
            //今天卖出：  昨日持有股票进入卖出
            dp[i][2]=dp[i-1][1]+prices[i];
            //今天冷冻期：昨天卖出
            dp[i][3]=dp[i-1][2];
            //今天已卖出且不在冷冻期：昨天是冷冻期； 昨天已经不在冷冻期
            dp[i][4]=max(dp[i-1][4],dp[i-1][3]);
        }

        return max(dp[len-1][2],max(dp[len-1][4],dp[len-1][3]));
    }
};