/* ************************************************************************
> File Name:		669修剪BST.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-09 10:39:39
> Link:		https://leetcode.cn/problems/trim-a-binary-search-tree/
> Description:		给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。通过修剪二叉搜索树，使得所有节点的值在[low, high]中。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // //bst，有序
        // //递归，边界？
        // if(!root) return root;
        // if(root->val<low)
        //     return trimBST(root->right,low,high);
        // if(root->val>high) 
        //     return trimBST(root->left,low,high);
        
        // root->left=trimBST(root->left,low,high);
        // root->right=trimBST(root->right,low,high);

        // return root;

        //迭代
        if(!root) return root;

          // 处理头结点，让root移动到[low, high] 范围内，注意是左闭右闭
        while (root != nullptr && (root->val < low || root->val > high)) {
            if (root->val < low) root = root->right; // 小于low往右走
            else root = root->left; // 大于high往左走
        }
        TreeNode *cur = root;
        // 此时root已经在[low, high] 范围内，处理左孩子元素小于low的情况
        while (cur != nullptr) {
            while (cur->left && cur->left->val < low) {
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }
        cur = root;

        // 此时root已经在[low, high] 范围内，处理右孩子大于high的情况
        while (cur != nullptr) {
            while (cur->right && cur->right->val > high) {
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }
        return root;
    }
};