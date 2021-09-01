/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        //贪心
        //int res=0;
        // for(int i=0;i<len-1;i++){
        //     if(prices[i]<prices[i+1]){
        //         res+=prices[i+1]-prices[i];
        //     }
        // }
        // return res;

        //动态规划
        //定义状态 dp[i][0] 表示第 i天交易完后手里没有股票的最大利润，
        //dp[i][1] 表示第 i 天交易完后手里持有一支股票的最大利润
        int dp[len][2];
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < len; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);//第i天没有持有，可能是i-1天也没有，或者是在第i天卖出，获得利润
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);//第i天持有，可能是第i-1天持有，i天继续持有；或i-1天没有，i天买入
        }

        return dp[len - 1][0];//最后一天不持有才会是答案

    }
};
// @lc code=end

