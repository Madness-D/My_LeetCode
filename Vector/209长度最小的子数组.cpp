/* ************************************************************************
> File Name:     209长度最小的子数组.cpp
> Author:        bwding
>  mail:         dingbuowen@outlook.com
> Created Time:  Thu 28 Apr 2022 04:17:37 PM CST
> link:          https://leetcode-cn.com/problems/minimum-size-subarray-sum/
> Description:   找出数组中满足其和 ≥ target 的长度最小的 连续子数组,返回其长度，否则返回0
> 思路：         两重循环暴力，或者双指针滑动窗口
 ************************************************************************/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len=nums.size();
        int ans=INT_MAX;
        int sum=0;
//两重循环 
/*
        for(int i=0;i<len;i++){
            sum=0;
            for(int j=i;j<len;j++){
                sum+=nums[j];
                if(sum>=target){
                    int subLen=j-i+1;
                    ans=ans>subLen?subLen:ans;
                    break;
                }
            }
        }
*/

//滑动窗口，若窗口内总和超过target，则左端点前进，计算长度更新答案
        int l=0;//左端点
        for(int r=0;r<len;r++){
            sum+=nums[r];
            while(sum>=target){//满足总和要求，计算更新答案
                int subLen=r-l+1;
                ans=ans>subLen?subLen:ans;
               //左端点收缩
                sum-=nums[l]; 
                l++;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};
