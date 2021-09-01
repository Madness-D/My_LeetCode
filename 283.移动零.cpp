/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len=nums.size();
        int p1=0,p2=0;//p1记录左侧0的位置
        for(;p2<len;){
            if(nums[p2]==0){++p2;}
            else{swap(nums[p1],nums[p2]);++p1;++p2;}
        }

    }
};
// @lc code=end

