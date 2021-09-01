/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    //递归
    bool is(TreeNode* p, TreeNode* q) {
        //DFS
        // if(!p && !q){//到达边界，都是null
        //     return true;
        // }else if(!p || !q){//一个null，另一个不是
        //     return false;
        // }else if(p->val!=q->val){
        //     return false;
        // }else{
        //     return isSameTree(p->left,q->right) && isSameTree(p->right,q->left);
        // }
    if(!p && !q) return true;
    if(!p || !q) return false;
    return p->val==q->val && is(p->left,q->right) && is(p->right,q->left);
    }

    bool check(TreeNode *u, TreeNode *v) {
        queue <TreeNode*> q;
        q.push(u); q.push(v);
        while (!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if (!u && !v) continue;
            if ((!u || !v) || (u->val != v->val)) return false;

            q.push(u->left); 
            q.push(v->right);

            q.push(u->right); 
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        
        //return is(root->left,root->right);

        //迭代  
        return check(root,root);

    }
};
// @lc code=end

