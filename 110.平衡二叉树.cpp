/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int height(TreeNode* root){//计算一个节点的高度
        if(!root) return 0;
        else return 1+max(height(root->left),height(root->right));
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        else return abs(height(root->left)-height(root->right))<=1 && isBalanced(root->left)&& isBalanced(root->right);
    }
};
// @lc code=end

