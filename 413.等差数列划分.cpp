/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 * 返回数组中的连续等差数列的个数
 * 若有一个等差数列，元素为n，则其共有(n-2)(n-1)/2个符合条件的子数列
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
         int len = nums.size();
    if (len < 3) {//无法构成等差数列
        return 0;
    }

    vector<int> diffs;//存储相邻元素之差
    for (int i = 0; i < len - 1; i++) {
        int mm = nums[i + 1] - nums[i];
        diffs.push_back(mm);//vector未分配空间，不可直接
    }

    vector<int> cons;//遍历diffs，存储相邻的相同元素个数
    int pos = 0;
    cons.push_back(1);
    for (int i = 1; i < diffs.size(); i++) {
        if (diffs[i] == diffs[i - 1]) { cons[pos]++; }
        else { pos++; cons.push_back(1); }
    }

    int res = 0;
    for (int i = 0; i < cons.size(); i++) {
        if (cons[i] == 1) { continue; }
        else { res += ((cons[i]) * (cons[i] - 1)) / 2; }
    }
    return res;
    }
};
// @lc code=end

