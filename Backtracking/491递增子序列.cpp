/* ************************************************************************
> File Name:		491递增子序列.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-19 20:34:44
> Link:		https://leetcode.cn/problems/increasing-subsequences/
> Description:		给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
     vector<vector<int>> ans;
    vector<int> path;
    void backtrack(vector<int>& nums, int idx){
        if(path.size()>1){
            ans.emplace_back(path);
            //如果直接return，就只有2个元素的符合条件了
            //return;
        }
        int a[201]={0};
        for(int i=idx;i<nums.size();i++){
            ////下面这样去重的要求是已经排序的，我们这里是未排序的，需要set或数组去重
           //if(i>idx && nums[i]==nums[i-1]) continue;
            if((!path.empty()&& nums[i]<path.back())||a[nums[i]+100] ){
                continue;}
                a[nums[i]+100]=1;
                path.emplace_back(nums[i]);
                backtrack(nums, i+1);
                path.pop_back();
            
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};