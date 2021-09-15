/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
private:
    vector<int> nums;
public:
 void inorder(TreeNode* root){
    if (root == nullptr) { return; }
    inorder(root->left);
    nums.push_back(root->val);//改成 空格
    inorder(root->right);
 }
    int kthSmallest(TreeNode* root, int k) {
        //中序遍历之后是递增序列
        inorder(root);
        return nums[k-1];

    }
};
// @lc code=end

