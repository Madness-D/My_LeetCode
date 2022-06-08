/* ************************************************************************
> File Name:		701BST插入.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-08 19:51:16
> Link:		https://leetcode.cn/problems/insert-into-a-binary-search-tree/
> Description:		给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value ，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。

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
    void dfs(TreeNode* root, int &val){
        if(!root) return ;
        if(val> root->val && !root->right) {root->right=new TreeNode(val); }
        else if(val<root->val & !root->left){ root->left=new TreeNode(val);  }
        else if(val>root->val) dfs(root->right,val);
        else   dfs(root->left,val);
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // //其实有多种符合条件的答案，这里选择向有空闲子结点位置的节点插入，即如果一个节点的右子节点为nullptr，而val又＞它，则插入
        // if(!root) {root=new TreeNode(val);return root;}
        // dfs(root,val);
        // return root;


        //迭代
        TreeNode* node=new TreeNode(val);
        if(!root) {
            return node;
        }

        TreeNode* cur=root;
        TreeNode* parent=root;
        while(cur){
            parent=cur;
            if(cur->val> val) cur=cur->left;
            else cur=cur->right;
        }
        if(parent->val>val) parent->left=node;
        else parent->right=node;
        return root;
    }
    
};