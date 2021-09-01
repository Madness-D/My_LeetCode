/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        //如果left为空，说明这两个节点在root结点的右子树上，我们只需要返回右子树查找的结果即可
        if (left == nullptr)
            return right;
        //同上
        if (right == nullptr)
            return left;
        //如果left和right都不为空，说明这两个节点一个在root的左子树上一个在root的右子树上，
        //我们只需要返回root结点即可。
        return root;

    }
};
// @lc code=end

