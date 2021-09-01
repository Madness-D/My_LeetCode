/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        //双重循环，超时
        // int p=0;
        // for(int i=0;i<len;i++){
        //     for(int j=i;j<len;j++){
        //         if(prices[j]-prices[i]>p){
        //             p=prices[j]-prices[i];
        //         }
        //     }
        // }
        // return p;

        // 对于第i天卖出，在之前的i-1天中的最低价时买入，这样收益最大
        // 设置lowest=100000记录最低价，设置maxprof=0记录收益
        //
        // int lowest=100000,maxprof=0;
        // for(int price:prices){
        //     maxprof=max(maxprof,price-lowest);
        //     lowest=min(lowest,price);
        // }
        // return maxprof;

        /*动态规划，第i天，max{前i-1天的最大收益，第i天的价格—前i-1天的最低价}
        边界条件 dp[0]=0
        */
       if(len==0) return 0;
       int lowest=prices[0];
       vector<int> dp(len,0);
       for(int i=1;i<len;i++){
           lowest=min(lowest,prices[i]);
           dp[i]=max(dp[i-1],prices[i]-lowest);
       }
       return dp[len-1];
    }
};
// @lc code=end

