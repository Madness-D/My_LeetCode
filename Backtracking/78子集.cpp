/* ************************************************************************
> File Name:		78子集.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-15 15:36:03
> Link:		https://leetcode.cn/problems/subsets/
> Description:		给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）
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
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return ans;

    }
};