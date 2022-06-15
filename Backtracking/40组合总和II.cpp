/* ************************************************************************
> File Name:		40组合总和II.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-15 10:46:51
> Link:		https://leetcode.cn/problems/combination-sum-ii/
> Description:		给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用 一次 。
注意：解集不能包含重复的组合。 

*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    vector<int> path;
public:
    void backtracking(vector<int>& candidates,int target, int sum,int idx){
        if(sum>target) return;
        if(sum==target){
            ans.emplace_back(path);
            return;
        }

        for(int i=idx;i<candidates.size()&& candidates[i]+sum<=target ;i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            
            path.emplace_back(candidates[i]);
            backtracking(candidates, target, sum+candidates[i],i+1);
            path.pop_back();

        //     //层间，避免重复，这是去掉for循环里面的i++
        //     //但这种方法，for里面嵌套一个while，不
        //    while(i+1<candidates.size() && candidates[i]==candidates[i+1]) i++;
        //     //if(i+1<candidates.size()) i++;
        //    i++;

        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //难点在于candidates数组里可能有重复的元素，但是最后的答案不允许重复
        //考虑树结构，允许元素在同一个树枝上重复（candidates里面的元素可以重复，即单个path里允许重复），
            //但是在同一层不允许重复，
        sort(candidates.begin(),candidates.end());
        backtracking(candidates, target, 0,0);
        return ans;
    }
};