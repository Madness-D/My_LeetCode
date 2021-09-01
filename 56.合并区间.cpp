/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //排序，排序之后如果
        if (intervals.size() == 0) {
            return {};
        }
    
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {//不重叠，或者为空
                merged.push_back({L, R});
            }
            else {//重叠，更新右端点
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};
// @lc code=end

