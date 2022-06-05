/* ************************************************************************
> File Name:		98验证二叉搜索树.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-05 16:55:35
> Link:		https://leetcode.cn/problems/validate-binary-search-tree/
> Description:		给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
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
     //二叉搜索树，中序遍历为非递减序列
    void inOrder(TreeNode * root, vector<int> &num){
        //if(!root) return;
        if(root->left) inOrder(root->left, num);
        num.emplace_back(root->val);
        if(root->right) inOrder(root->right, num);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> num;
        inOrder(root, num);
        for(int i=0;i<num.size()-1;i++){
            if(num[i]>=num[i+1]) return false;
        }
        return true;
    }
};