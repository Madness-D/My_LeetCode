/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    void inOrder(TreeNode* root, vector<int> &num){
        if(!root) return;
        inOrder(root->left,num);
        num.push_back(root->val);
        inOrder(root->right,num);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> num;
        inOrder(root,num);
        int len=num.size();
        int l=0,r=len-1;
        while(l<r){
            if(num[l]+num[r]<k) l++;
            else if(num[l]+num[r]>k) r--;//else不能省
            else if(num[l]+num[r]==k) return true;
        }

        return false;
    }
};
// @lc code=end

