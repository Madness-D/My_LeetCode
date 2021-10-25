/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //遍历,比较
        for(int i=0;i<nums.size();i++){
            if(target==nums[i])
                return i;
        }
        return -1;
    }
};
// @lc code=end

