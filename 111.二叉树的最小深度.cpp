/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
    //递归，DFS
    //     if(root==nullptr){
    //         return 0;
    //     }
    //     int left=minDepth(root->left);
    //     int right=minDepth(root->right);
    //    if(root->left && root->right) 
    //         return 1+min(left,right);
    //     else return left==0?right+1:left+1;

    //BFS，找到的第一个叶子结点一定是深度最小的叶子结点
        if(root==nullptr){
            return 0;
        }

        queue<pair<TreeNode *, int> > que;//定义一个pair，第二个记录层数 秒啊
        que.emplace(root, 1);
        while (!que.empty()) {
            TreeNode *node = que.front().first;
            int depth = que.front().second;
            que.pop();
            if (node->left == nullptr && node->right == nullptr) {
                return depth;
            }
            if (node->left != nullptr) {
                que.emplace(node->left, depth + 1);
            }
            if (node->right != nullptr) {
                que.emplace(node->right, depth + 1);
            }
        }
        return 0;

    }
};
// @lc code=end

