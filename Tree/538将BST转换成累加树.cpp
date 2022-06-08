/* ************************************************************************
> File Name:		538将BST转换成累加树.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-08 21:14:36
> Link:		https://leetcode.cn/problems/convert-bst-to-greater-tree/
> Description:		给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。

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
    void dfs(TreeNode* root, int &sum){
        if(!root) return;
        dfs(root->right,sum);
        root->val+=sum;
        sum=root->val;
        dfs(root->left,sum);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        //中序遍历为 左中右
        //这里需要反过来。右中左，然后维护一个sum
        int sum=0;
        dfs(root,sum);
        return root;
    }
};