/* ************************************************************************
> File Name:     977有序数组的平方.cpp
> Author:        bwding
>  mail:         dingbuowen@outlook.com
> Created Time:  Thu 28 Apr 2022 03:39:08 PM CST
> link:          https://leetcode-cn.com/problems/squares-of-a-sorted-array/
> Description:   给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 ************************************************************************/

//思路：很直接，双指针，从原数组的两端往中间一次计算平方值，比较，易得到降序的结果
//之后可以直接pushback然后用reverse函数反转一下，或者是直接根据下标倒序存放
//reverse函数的复杂度也是O(n)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //reverse 的复杂度为O(n)
        int l=0,r=nums.size()-1;
        vector<int> ans;
        while(l<=r){
            if(nums[l]*nums[l]>=nums[r]*nums[r]){
                ans.emplace_back(nums[l]*nums[l]);
                l++;
            }else{
                ans.emplace_back(nums[r]*nums[r]);
                r--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};

