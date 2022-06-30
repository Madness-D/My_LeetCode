/* ************************************************************************
> File Name:		714买卖股票含手续费.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-30 20:02:13
> Link:		https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //更直观的想法是dp

        //贪心---将手续费放在买入时计算，即价格+手续费是买入价格
        //什么时候卖出？ 只要当前价格>买入价格， 就可以认为卖出，收获利润

        int ans=0;
        int minPri=prices[0]+fee;
        for(int i=1;i<prices.size();i++){
            //如果价格更低,买入
            if(prices[i]+fee<minPri){
                //更新买入价格
                minPri=prices[i]+fee;
            }else if(prices[i]> minPri){ //这里的minpri设置的和carl不太一样
                ans+=prices[i]-minPri;
                minPri=prices[i];
            }
        }
        return ans;

    }
};