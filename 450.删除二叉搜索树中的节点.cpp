/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* findMax (TreeNode* root){
        while(root->right!=nullptr){
            root=root->right;
        }
        return root;
    }

    TreeNode* findMin(TreeNode* root){
        while(root->left!=nullptr){
            root=root->left;
        }
        return root;
    }
    void mydeleteNode(TreeNode* &root,int x){//删除值为x的结点
    if(root==nullptr) return;
    if(root->val ==x){//找到结点
        if(root->left==nullptr && root->right==nullptr){
            root=nullptr;
        }else if(root->left!=nullptr){//左子树非空，删除前驱
            TreeNode* pre=findMax(root->left);
            root->val=pre->val;
            mydeleteNode(root->left,pre->val);//?
        }else{
            TreeNode* next=findMin(root->right);
            root->val=next->val;
            mydeleteNode(root->right,next->val);
        }
    }else if(root->val>x){
        mydeleteNode(root->left,x);
    }else{
        mydeleteNode(root->right,x);
    }

}

    TreeNode* deleteNode(TreeNode* root, int key) {
        //写一个函数，查找，返回
        mydeleteNode(root,key);
        return root;
    }
};
// @lc code=end

