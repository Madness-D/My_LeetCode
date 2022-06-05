/* ************************************************************************
> File Name:		404左叶子之和.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-26 19:45:12
> Link:		https://leetcode.cn/problems/sum-of-left-leaves/
> Description:		给定二叉树的根节点 root ，返回所有左叶子之和。
> 思路：        左叶子，需要从其父节点判断
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
     void dfs(TreeNode* root, int &sum){
        if(!root) return ;
        if(root->left &&  !root->left->left && !root->left->right) sum+=root->left->val;
        dfs(root->left,sum);
        dfs(root->right,sum);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        dfs(root,sum);
        return sum;

        // //栈，迭代
        // if(!root) return 0;
        // stack<TreeNode*> st;
        // int sum=0;
        // st.push(root);
        // while(!st.empty()){
        //     TreeNode* node=st.top();
        //     st.pop();
        //     if(node->left && !node->left->left && !node->left->right)  sum+=node->left->val;
        //     if(node->left) st.push(node->left);
        //     if(node->right) st.push(node->right);
        // }
        // return sum;
    }
};