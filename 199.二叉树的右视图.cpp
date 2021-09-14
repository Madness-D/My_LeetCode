/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        //或许应该用栈
        //层序遍历，如何实现 只输出一层中的最后一个？
        
        vector<int> res;
        if(root==nullptr) return res;
        queue<TreeNode*> q;//存地址的队列
        q.push(root);
        while (!q.empty()) {
           //此时队尾元素即为该层最右侧的元素 
           res.push_back(q.back()->val);
           int len=q.size();
           //将下一层的结点入队，并且将该层的元素pop出去
            while (len--)
            {
            TreeNode* now = q.front();
            q.pop();
            if (now->left != nullptr) { q.push(now->left); }
            if (now->right != nullptr) { q.push(now->right); }
            }
            //TreeNode* now = q.front();
            // q.pop();
            //cout << now->val << '\n';
            
            
        }
    
    return res;

    }
};
// @lc code=end

