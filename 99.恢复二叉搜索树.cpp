/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    //二叉搜索树,如果是中序遍历,得到的应该是递增的序列
    void markTree(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& end) {
        if (!root) return;
        markTree(root->left, prev, first, end);
        if (prev) {
            if (root->val < prev->val) {
                if (!first) {
                    first = prev;
                }
                end = root;
            }
        }
        prev = root;
        markTree(root->right, prev, first, end);
    }
public:
    void recoverTree(TreeNode* root) {
        
        TreeNode *prev = nullptr, *first = nullptr, *end = nullptr;
        markTree(root, prev, first, end);
        swap(first->val, end->val);
        return;

    }
};
// @lc code=end

