/* ************************************************************************
> File Name:		144前序遍历.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-24 20:06:33
> Link:		https://leetcode.cn/problems/binary-tree-preorder-traversal/
> Description:		给你二叉树的根节点 root ，返回它节点值的前序遍历。
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
    void preOrder(TreeNode* root, vector<int> &ans){
        if(!root) return;
        else{
            ans.emplace_back(root->val);
            preOrder(root->left, ans);
            preOrder(root->right, ans);
            return ;
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // preOrder(root, ans);
        // return ans;

        //栈，迭代，基于后序遍历的方法
        //先构造：中右左，再reverse--->左右中
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode* > st;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur=st.top();
            ans.emplace_back(cur->val);
            st.pop();
            if(cur->left) st.push(cur->left);
            if(cur->right) st.push(cur->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};