/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int Max=INT_MIN;
    int dfs(TreeNode* root){
        if(root==nullptr) return 0;
        int leftSum=max(0,dfs(root->left));
        int rightSum=max(0,dfs(root->right));
        Max=max(Max,leftSum+rightSum+root->val);
        return max(leftSum,rightSum)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return Max;

    }
};
// @lc code=end

