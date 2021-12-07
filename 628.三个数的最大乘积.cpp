/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */

// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        //贪心,先排个序
        sort(nums.begin(),nums.end());
        int l=nums.size();
        return max(nums[l-1]*nums[l-2]*nums[l-3],nums[l-1]*nums[0]*nums[1]);
    
    }
};
// @lc code=end

