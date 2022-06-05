/* ************************************************************************
> File Name:		112路径总和.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-26 22:26:26
> Link:		https://leetcode.cn/problems/path-sum/
> Description:		给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。

*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
 bool hasPathSum(TreeNode* root, int targetSum) {
     //递归
        if(!root) return false;
        if(!root->left && !root->right) return targetSum==root->val;
        else {
            int t=root->val;
            return hasPathSum(root->left,targetSum-t) || hasPathSum(root->right, targetSum-t);
        }
    }
    
};