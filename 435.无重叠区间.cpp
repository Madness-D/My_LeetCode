/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int> &r1,vector<int> &r2){
        return r1[1]<r2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //按左端点排序，然后遍历？
        //按右端点排序，求出最多多少个区间不重叠
        if(intervals.empty()){
            return 0;
        }

        sort(intervals.begin(),intervals.end(),cmp);

        int n = intervals.size();
        int right = intervals[0][1];//初始值
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] >= right) {//不重叠
                ++ans;
                right = intervals[i][1];
            }
        }
        return n - ans;

    }
};
// @lc code=end

