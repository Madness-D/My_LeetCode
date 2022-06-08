/* ************************************************************************
> File Name:		235BST的最近公共祖先.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-07 10:10:20
> Link:		https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
> Description:		给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {   //注意BST的性质，节点有序
        //如果root刚好处于p和q之间，则是分岔点？

       // int pp=p->val,qq=q->val;

        ////队列，中序遍历
        // queue<TreeNode*> qu;
        // qu.push(root);
        // while(!qu.empty()){
        //     int len=qu.size();
        //     while(len--){
        //         int rv=qu.front()->val;
        //         if((long)(rv-pp)*(rv-qq)<=0) return qu.front();
        //         if(qu.front()->left) qu.push(qu.front()->left);
        //         if(qu.front()->right) qu.push(qu.front()->right);
        //         qu.pop();
        //     }
        // }

        // //迭代
        // while(root){
        //     if(root->val>pp && root->val> qq) root=root->left;
        //     else if(root->val <pp && root->val< qq) root=root->right;
        //     else return root;
        // }

       // return nullptr;


        //递归，同样是比大小，来改变root值
        if(root->val> p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        else if(root->val< p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        return root;
        
    }
};