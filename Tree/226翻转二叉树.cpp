/* ************************************************************************
> File Name:		226翻转二叉树.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-25 00:27:12
> Link:		https://leetcode.cn/problems/invert-binary-tree/
> Description:		给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // //递归
        // if(!root) return root;
        // TreeNode* tl=root->left;
        // root->left=invertTree(root->right);
        // root->right=invertTree(tl);
        // return root;


        if (root == NULL) return root;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
           TreeNode* tt=st.top();
           st.pop();
           swap(tt->left,tt->right);
           if(tt->left) st.push(tt->left);
           if(tt->right) st.push(tt->right);
       }
       return root;
    }
};