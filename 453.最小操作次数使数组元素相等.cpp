/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0;
        for(int num:nums){
            res+=num-nums[0];
        }
        return res;
    }
};
// @lc code=end

