/* ************************************************************************
> File Name:		216组合总和III.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-14 23:16:05
> Link:		https://leetcode.cn/problems/combination-sum-iii/submissions/
> Description:		找出所有相加之和为 n 的 k 个数的组合，
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    vector<int> path;
public:
     void backtracking(int k,int n,int sum,int start ){
        if(sum>n) return ;
        if(path.size()==k && sum==n) {
            ans.emplace_back(path);
            return;
        }
        for(int i=start;i<=9-(k-path.size())+1;i++){
            path.emplace_back(i);
            backtracking(k, n, sum+i, i+1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 0, 1);
        return ans;
    }
};