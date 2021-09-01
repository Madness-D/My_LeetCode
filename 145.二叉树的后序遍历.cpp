/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    void postorder(TreeNode* root,vector<int> &res){
         if(root==nullptr){return ;}
           postorder(root->left,res);
           postorder(root->right,res); 
           res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        //postorder(root,res);


        //迭代
        //本质和递归一样，只是显式使用栈
        if(root==nullptr){ return res; }
        stack<TreeNode *> stk;
        TreeNode *prev = nullptr;
        while (root != nullptr || !stk.empty()) {
            //遍历到最左边子节点
            while (root != nullptr) {
                stk.emplace(root);
                root = root->left;
            }

            //左边子树出栈
            root = stk.top();
            stk.pop();

            if (root->right == nullptr || root->right == prev) {
                //此时左右子树已经都被访问了，将根节点存入
                res.emplace_back(root->val);
                //避免重复访问右子树，记录当前结点便于下一步对比
                prev = root;
                //避免重复访问左子树，设置nullptr，见上面while条件
                root = nullptr;
            } 
            else {//遍历最左边子节点的右子树(右子树存在且未访问过)
                //重复压栈，记录路径分叉结点
                stk.emplace(root);
                root = root->right;
            }
        }
        return res;

    }
};
// @lc code=end

