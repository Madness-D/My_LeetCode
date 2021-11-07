/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 范围求和 II
 */

// @lc code=start
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.size()==0) return m*n;
        int min_m=INT_MAX,min_n=INT_MAX;
        for(vector<int> nn:ops){
            min_m=min(min_m,nn[0]);
            min_n=min(min_n,nn[1]);
        }
        return min_m*min_n;
    }
};
// @lc code=end

