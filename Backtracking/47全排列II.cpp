/* ************************************************************************
> File Name:		47全排列II.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-19 21:26:30
> Link:		https://leetcode.cn/problems/permutations-ii/
> Description:		给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking( vector<int>& nums,vector<int>& used){
        if(path.size()==nums.size() ){
            ans.emplace_back(path);
            return;
        }
        //和前面的组合问题是类似的，元素可能重复，
        //但是又不允许在同一层中使用。如允许1，1，2； 但不允许1，1，2出现两次
        for(int i=0;i<nums.size();i++){
            //先将nums排序
            //如果前面重复的元素没用过，则这个元素
            if(i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;
            //
            if(!used[i]){
            used[i]=1;
            path.emplace_back(nums[i]);
            backtracking(nums,used);
            used[i]=0;
            path.pop_back();
            }
        }
    }
public:
     vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> used(nums.size(),0);
        sort(nums.begin(),nums.end());
        backtracking(nums,used);
        return ans;
    }
};