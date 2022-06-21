/* ************************************************************************
> File Name:		46全排列.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-19 20:45:46
> Link:		https://leetcode.cn/problems/permutations/
> Description:		给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    //回顾，C++里面数组只能引用传递，即传递的是首元素地址
    void backtracking( vector<int>& nums,int a[21]){
        if(path.size()==nums.size() ){
            ans.emplace_back(path);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(a[nums[i]+10]) continue;
            a[nums[i]+10]=1;
            path.emplace_back(nums[i]);
            backtracking(nums,a);
            a[nums[i]+10]=0;
            path.pop_back();
        }
    }
public:
     vector<vector<int>> permute(vector<int>& nums) {
        int a[21]={0};
        backtracking(nums, a);
        return ans;
    }
};