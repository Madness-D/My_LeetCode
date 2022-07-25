/* ************************************************************************
> File Name:		714买卖股票含手续费.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-25 13:53:22
> Link:		https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //fee是买入时交？还是卖出时交？
        //先按照买入时交
        int len=prices.size();
        vector<vector<int>> dp(len,vector<int>(2,0));
        //0不持有 1持有
        dp[0][1]=-prices[0]-fee;
        for(int i=1;i<len;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]-fee);
        }

        return dp[len-1][0];


        //贪心：将手续费归入到股价中，见贪心那个文件夹

    }
};