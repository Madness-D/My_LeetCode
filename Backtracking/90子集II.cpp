/* ************************************************************************
> File Name:		90子集II.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-15 15:40:15
> Link:		https://leetcode.cn/problems/subsets-ii/
> Description:		给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

//// 参考40组合总和II
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    vector<int> path;

    void backtracking(vector<int>& nums,int idx){
        //回溯终止条件
        //这道题要存所有子集合，因此不是终止的时候存,而是每个回溯的节点都存一下
        ans.emplace_back(path);
        if(idx>=nums.size()){
            return;
        }
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]){continue;}
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //关键在于，子集里有重复的元素，因此考虑像之前的组合和一样
        sort(nums.begin(),nums.end());
        backtracking(nums, 0);
        return ans;

    
    }
};