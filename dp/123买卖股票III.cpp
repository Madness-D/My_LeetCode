/* ************************************************************************
> File Name:		123买卖股票III.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-23 20:13:13
> Link:		https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/
> Description:		最多两笔交易
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //分析状态，  从未购入股票，第一次买入及以后， 第一次卖出及以后， 第二次买入。。。，第二次卖出。。。
        //              0           1                       2                  3                4
        int len=prices.size();

        vector<vector<int>> dp(len,vector<int>(5,0));
        //边界,
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        dp[0][3]=-prices[0]; //这里的第二次买入，其实也可能是第一次买入
        for(int i=1;i<len;i++){
           // dp[i][0]=dp[i-1][0];//不买就还是不买
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
            dp[i][2]=max(dp[i-1][2],dp[i-1][1]+prices[i]);
            dp[i][3]=max(dp[i-1][3],dp[i-1][2]-prices[i]);
            dp[i][4]=max(dp[i-1][4],dp[i-1][3]+prices[i]);
        }
        return dp[len-1][4];
    }
};