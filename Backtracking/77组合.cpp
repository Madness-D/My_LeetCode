/* ************************************************************************
> File Name:		77组合.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-09 20:03:20
> Link:		https://leetcode.cn/problems/combinations/
> Description:		给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;
    vector<int> path;
public:
     void backtracking(int n,int k,int startIdx){
        //终止条件
        if(path.size()==k){
            ans.emplace_back(path);
            //path.pop_back();
            return ;
        }
        // //横向遍历
        // for(int i=startIdx;i<=n;i++){
        //剪枝，如果后面的元素个数已经不足所需元素个数，就不必搜索了
        //  需要总共k个元素，已经有path.size()个，
        for(int i=startIdx;i<=n-(k-path.size())+1;i++){
            path.emplace_back(i);
            //纵向遍历
            backtracking(n, k, i+1);
            //回退
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return ans;

    }
};