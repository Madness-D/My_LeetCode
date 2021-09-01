/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    //递归
    // void preorder(TreeNode* root, vector<int> &res){
    //     if(root==nullptr){ return;}
    //     res.push_back(root->val);
    //     preorder(root->left,res);
    //     preorder(root->right,res);
    // }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        //preorder(root,res);
        //return res;

        //迭代
        //本质和递归一样，只是显式使用栈
        if(root==nullptr){ return res; }

        stack<TreeNode*> st;
        TreeNode* curr=root;
        while(!st.empty() || curr!=nullptr){
             while (curr != nullptr) {
                 //emplace是c++11的新特性，优化性能
                res.emplace_back(curr->val);
                st.emplace(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            curr = curr->right;
        }
        return res;
    }
};
// @lc code=end

