/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans = 0;
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                ans = max(ans, DFS(grid, i, j,m,n));
            }
        }
        return ans;
    }


    int DFS(vector<vector<int>>& grid,int r, int c, int m, int n){
        if(r < 0 || c < 0 || r == m || c == n || !grid[r][c]) return 0 ;
        else {
            int res=1;
            grid[r][c]=0;// 
            res+=DFS(grid,r+1,c,m,n);
            res+=DFS(grid,r-1,c,m,n);
            res+=DFS(grid,r,c+1,m,n);
            res+=DFS(grid,r,c-1,m,n);
            return res;
        }     
    }
    
};
// @lc code=end

