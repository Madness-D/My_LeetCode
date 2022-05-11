/* ************************************************************************
> File Name:		15三数之和.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-11 20:44:11
> Link:		https://leetcode.cn/problems/3sum/
> Description:		给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。

> 思路： 重点和难点在于如何去掉重复的三元组，这道题虽然归类于hash，但应该用双指针来做

*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len=nums.size();
        sort(nums.begin(),nums.end());

        if(len<3 || nums[0]>0) return {};

        vector<vector<int>> ans;
        for(int i=0;i<len;i++){
            if(nums[i]>0) return ans;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l=i+1,r=len-1;
            int target=-nums[i];
            while(l<r){
                int t=nums[l]+nums[r];
                if(t==target) {
                    vector<int> vtt={nums[i],nums[l],nums[r]};
                    ans.emplace_back(vtt);
                    while(l<r && nums[l]==nums[l+1]) l++;
                    while(l<r && nums[r]==nums[r-1]) r--;
                    l++;r--;
                    }
                else if(t<target) {l++;
                    while(l<r && nums[l]==nums[l-1]) l++;}
                else {r--; 
                    while(l<r && nums[r]==nums[r+1]) r--;}
            }

        }
        return ans;
    }
};