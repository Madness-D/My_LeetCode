/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        //
    // int n = nums.size(), count = 0;
    // for (int i = 1; i < n; i++)
    //     if (nums[i] == nums[i - 1 - count]) count++;
    //     else nums[i - count] = nums[i];
    // return n - count;
    // }

    //双指针
    int n = nums.size();
    if(n==0){return 0;}
    int l=1,r=1;
    while(r<n){
        if(nums[r]!=nums[l-1]){//l-1,r-1也可以
            nums[l]=nums[r];
            l++;
        }
        r++;
    }
    return  l;
    }
};
// @lc code=end

