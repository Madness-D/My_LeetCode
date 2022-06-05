/* ************************************************************************
> File Name:		700二叉搜索树中的搜索.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-05 16:47:04
> Link:		https://leetcode.cn/problems/search-in-a-binary-search-tree/
> Description:		在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 
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
    TreeNode* searchBST(TreeNode* root, int val) {
        ////递归
        // if(!root || root->val==val) return root;
        // else if(root->val>val) return searchBST(root->left, val);
        // else if(root->val<val) return searchBST(root->right,val);
        // else return nullptr;

        //迭代
        while(root){
            if(root->val==val) return root;
            else if(root->val>val) root=root->left;
            else root=root->right;
        }
        return nullptr;
    }
};