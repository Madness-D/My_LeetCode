/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    ////count记录需要删除的元素的个数
    // int n = nums.size(), count = 0;
    // for (int i = 2; i < n; i++)
    //     if (nums[i] == nums[i - 2 - count]) count++;
    //     else nums[i - count] = nums[i];
    // return n - count;

    //双指针
    int n = nums.size();    
    if(n<=2){return n;}
    int l=2,r=2;
    while(r<n){
        if(nums[r]!=nums[l-2]){
            nums[l]=nums[r];
            //if(l+2<n){l+=2;}
            l++;
        }
        r++;
    }
    return  l;

    }
};
// @lc code=end

