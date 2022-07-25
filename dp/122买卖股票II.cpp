/* ************************************************************************
> File Name:		122买卖股票II.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-23 16:55:51
> Link:		https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
> Description:		允许多次买卖，但最多只能持有一个股票
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //贪心的不提了


        //动态规划
        //某一天，股票只有两种可能，持有股票、不持有股票, 两种情况下的最大收益 分别对应dp[i][0]  dp[i][1]
        int len=prices.size();
        vector<vector<int>> dp(len,vector<int> (2,0));
        dp[0][0]=-prices[0];
        for(int i=1;i<len;i++){
            //注意下面这行和121不同
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]-prices[i]);
            dp[i][1]=max(dp[i-1][0]+prices[i], dp[i-1][1]);
        }
        return dp[len-1][1] ;
    }
};