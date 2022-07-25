/* ************************************************************************
> File Name:		121买卖股票.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-23 16:08:05
> Link:		https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // //贪心的方法不再叙述
        // //只要后面有比这个大的就可以买入
        // //连续的持有，可以看作当天卖出又买入
        // int ans=0;
        // for(int i=1;i<prices.size();i++){
        //     if(prices[i]>prices[i-1]) ans+=prices[i]-prices[i-1];
        // }
        // return ans;

        //动态规划
        //某一天，股票只有两种可能，持有股票、不持有股票, 两种情况下的最大收益 分别对应dp[i][0]  dp[i][1]
        int len=prices.size();
        vector<vector<int>> dp(len,vector<int> (2,0));
        dp[0][0]=-prices[0];
        for(int i=1;i<len;i++){
            //注意，题目限定只能买卖一次，则第i天买入股票的话就不考虑之前买卖带来的收益，即直接是-prices[i]
            dp[i][0]=max(dp[i-1][0],-prices[i]);
            dp[i][1]=max(dp[i-1][0]+prices[i], dp[i-1][1]);
        }
        return dp[len-1][1];
    }
};