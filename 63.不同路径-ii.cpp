/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        /*

        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        //动态规划
        vector<vector<int>> dp(m,vector<int>(n));
        //dp[m-1][n-1]=0;
        if(obstacleGrid[m-1][n-1]==1)
            return 0;

        // for(int i=0;i<n;i++){
        //     if(obstacleGrid[m-1][i]==0){
        //     dp[m-1][i]=1;}
        // }  
        // for(int j=0;j<m;j++){
        //     if(obstacleGrid[j][n-1]==0){
        //     dp[j][n-1]=1;}
        // }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }
            }
        }

        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(obstacleGrid[i][j]==0){
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
                }
            }
        }

        return dp[0][0];

        */

        //这里的dp[i][j]记录从0，0出发到达i，j的路径数
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        vector<vector<int>>dp(m,vector<int>(n));
        dp[0][0] = !obstacleGrid[0][0];

        for(int i = 0;i<m && obstacleGrid[i][0] == 0;i++)
        {
            dp[i][0] = 1;
        }
        for(int j = 0;j<n && obstacleGrid[0][j] == 0;j++)
        {
            dp[0][j] = 1;
        }

        for(int i = 1;i<m;i++)
        {
            for(int j = 1;j<n;j++)
            {
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

