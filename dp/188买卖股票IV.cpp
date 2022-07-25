/* ************************************************************************
> File Name:		188买卖股票IV.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-25 10:51:42
> Link:		https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //类比123买卖股票III， 一个股票有2*k+1个状态
        // 0 未购买股票
        // 2*i-1  第i次购入
        //2*i  第i次卖出
        int len=prices.size();
        if(len==0) return 0;
        vector<vector<int>> dp(len,vector<int>(2*k+1,0));
        for(int i=1;i<2*k+1;i+=2){
            dp[0][i]=-prices[0];
        }
        // for(int i=2;i<2*k+1;i+=2){
        //     dp[0][i]=prices[0];
        // }
        for(int i=1;i<len;i++){
            for(int j=0;j<2*k;j+=2){ //j步长为2
                //dp[i][0]==0,不再叙述
                dp[i][j+1]=max(dp[i-1][j+1],dp[i-1][j]-prices[i]);
                dp[i][j+2]=max(dp[i-1][j+2],dp[i-1][j+1]+prices[i]);
            }
        }
        return dp[len-1][2*k];
    }
};