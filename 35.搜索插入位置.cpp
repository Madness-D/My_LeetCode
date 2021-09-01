/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    bool isBiger(int nu,int target){
        if(nu>=target) return true;
        else return false;
    }
    int searchInsert(vector<int>& nums, int target) {
        int len=nums.size();
        int left=0,right=len-1,mid;
         while(left<=right){
        mid=left + (right - left) / 2;
        //if(left==right) return left;
        if(isBiger(nums[mid],target)) right=mid-1;
        else left=mid+1;
        }  
        return left;

    }
};
// @lc code=end

