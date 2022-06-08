/* ************************************************************************
> File Name:		236二叉树的最近公共祖先.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-07 10:00:15
> Link:		https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
> Description:		给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
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
    bool isAncestor(TreeNode* r,TreeNode* c){
        if(r==c) return true;
        if(!r && c) return false;
        return isAncestor(r->left,c)||isAncestor(r->right, c);
    }
    bool isCommonAncestor(TreeNode* r,TreeNode* p,TreeNode* q){
        return isAncestor(r,p)&&isAncestor(r, q);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // //一个节点x，它是p和q的祖先结点，而x的子结点不是p和q的子结点，则其是最近公共祖先
        // //但这种方法，复杂度应该是O(n^2)
        // queue<TreeNode*> qu;
        // qu.push(root);
        // while(!qu.empty()){
        //     int len=qu.size();
        //     while(len--){
        //     TreeNode* r=qu.front();
        //     if(isCommonAncestor(r, p, q)&& !isCommonAncestor(r->left, p, q)&&!isCommonAncestor(r->right, p, q)) return r;
        //     if(r->left) qu.push(r->left);
        //     if(r->right) qu.push(r->right);
        //     qu.pop();
        //     }
        // }
        // return nullptr;

        //后序遍历是天然的回溯
        //递归，返回值不为0则说明找到了p或者q
        if(root==p||root==q || root==nullptr) return root;
        TreeNode * left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(left && right) return root;
        else if(left && !right) return left;
        else return right;
    }
};