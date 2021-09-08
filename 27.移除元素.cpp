/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int l=0,r=0;
        for(;r<n;r++){
            if (nums[r] != val) {
                nums[l] = nums[r];
                l++;
            }
        }
        return l;

    }
};
// @lc code=end

