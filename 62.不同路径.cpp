/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        //动态规划
        vector<vector<int>> dp(m,vector<int>(n));
        //dp[m-1][n-1]=0;
        for(int i=0;i<n;i++){
            dp[m-1][i]=1;
        }  
        for(int j=0;j<m;j++){
            dp[j][n-1]=1;
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }

        return dp[0][0];
    }
};
// @lc code=end

