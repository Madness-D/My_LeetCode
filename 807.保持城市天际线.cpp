/*
 * @lc app=leetcode.cn id=807 lang=cpp
 *
 * [807] 保持城市天际线
 */

// @lc code=start
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int x=grid.size(),y=grid[0].size();
        vector<int> xhigh(x,INT_MIN);
        vector<int> yhigh(y,INT_MIN);
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                int hh=grid[i][j];
                xhigh[i]=max(xhigh[i],hh);
                yhigh[j]=max(yhigh[j],hh);
            }
        }
        int res=0;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                int hh=grid[i][j];
                int temp=min(xhigh[i],yhigh[j]);
                res+=temp-hh;
            }
        }
        return res;
    }
};
// @lc code=end

