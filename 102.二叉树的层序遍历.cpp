/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr){
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int levelSize=que.size();
            res.push_back(vector<int>());//不要限定size，否则会补0
            for(int i=0;i<levelSize;i++){
                TreeNode* node=que.front();
                que.pop();
                res.back().push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }

        }
        return res;
    }
};
// @lc code=end

