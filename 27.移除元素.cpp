/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //滑动窗口
        int n=nums.size();
        int l=0,r=0;
        for(;r<n;r++){
            if (nums[r] != val) {
                nums[l] = nums[r];
                l++;
            }
        }
        return l;

        // //暴力
        // int size=nums.size();
        // for(int i=0;i<size;i++){
        //     if(nums[i]==val){ //需要删除
        //     for(int j=i+1;j<size;j++){
        //         nums[j-1]=nums[j];
        //     }
        //     size--;
        //     i--;
        //     }
        // }
        // return size;
    }
};
// @lc code=end

