/* ************************************************************************
> File Name:		39组合总数.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-15 10:01:58
> Link:		https://leetcode.cn/problems/combination-sum/
> Description:		给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合

*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    vector<int> path;
public:
     void backtracking(vector<int>& candidates,int target, int sum,int idx){
        //if(sum>target) return;
        if(sum==target){
            ans.emplace_back(path);
            return;
        }
        //配合sort、剪枝
        for(int i=idx;i<candidates.size()&& candidates[i]+sum<=target ;i++){
            path.emplace_back(candidates[i]);
            //可以重复选取，但不能回头选更小的
            backtracking(candidates, target, sum+candidates[i],i);
            path.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtracking(candidates, target, 0,0);
        return ans;
    }
};