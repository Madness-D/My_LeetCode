/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int rows = grid.size(), columns = grid[0].size();
        auto dp = vector < vector <int> > (rows, vector <int> (columns));

        dp[rows-1][columns-1]=grid[rows-1][columns-1];
        for(int i=rows-2;i>=0;--i){
            dp[i][columns-1]=dp[i+1][columns-1]+grid[i][columns-1];
        }
        for(int i=columns-2;i>=0;--i){
            dp[rows-1][i]=dp[rows-1][i+1]+grid[rows-1][i];
        }
        for(int i=rows-2;i>=0;--i){//注意循环的顺序
            for(int j=columns-2;j>=0;--j){
                dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];

    }
};
// @lc code=end

