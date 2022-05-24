/* ************************************************************************
> File Name:		94中序遍历.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-24 19:54:31
> Link:		https://leetcode.cn/problems/binary-tree-inorder-traversal/
> Description:		给定一个二叉树的根节点 root ，返回它的中序遍历 。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    //递归
     void inOrder(TreeNode* root, vector<int> &ans){
        if(!root) return;
        else{
            inOrder(root->left, ans);
            ans.emplace_back(root->val);
            inOrder(root->right, ans);
           
            return ;
        }
    }
public:
     vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // inOrder(root,ans);
        // return ans;


        //迭代，把递归的栈显式地写出来
        //左中右，需要先深入到左边的最底层，再处理节点，处理顺序和访问顺序是不一致的。
        //借用指针的遍历来帮助访问节点，栈则用来处理节点上的元素

        vector<int> ans;
        if(!root) return ans;

        stack<TreeNode*> st;
        TreeNode* curr=root;
        while(!st.empty()|| curr){
            if(curr){
                st.push(curr);
                curr=curr->left;
            }else{
                curr=st.top();
                ans.emplace_back(curr->val);
                st.pop();
                curr=curr->right;    
           }
        }
        return ans;

    }
};