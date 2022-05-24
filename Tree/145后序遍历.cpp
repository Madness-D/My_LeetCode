/* ************************************************************************
> File Name:		145后序遍历.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-24 20:07:40
> Link:		https://leetcode.cn/problems/binary-tree-postorder-traversal/
> Description:		给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
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
    void postOrder(TreeNode* root, vector<int> &ans){
        if(!root) return;
        else{
            
            postOrder(root->left, ans);
            postOrder(root->right, ans);
            ans.emplace_back(root->val);
            return ;
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // postOrder(root, ans);
        // return ans;



        //栈，迭代
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();                       // 中
            st.pop();
            result.push_back(node->val);
            //因为栈的出栈顺序与入栈顺序相反，因此先入right
            if (node->right) st.push(node->right);           // 右（空节点不入栈）
            if (node->left) st.push(node->left);             // 左（空节点不入栈）
        }
        return result;
    }
};