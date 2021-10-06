/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
//dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j+nums[i]]
//i=0,dp=0
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        if(target>sum || target <-sum){
            return 0;
        }
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum*2+1));
        dp[0][sum]=1;
        for(int row=0;row<nums.size();row++){
            for(int col=0;col<dp[row].size();col++){
                if(dp[row][col]){
                    dp[row+1][col-nums[row]]+=dp[row][col];
                    dp[row+1][col+nums[row]]+=dp[row][col];
                }
            }
        }
    return dp[nums.size()][sum+target];
    }
};
// @lc code=end

