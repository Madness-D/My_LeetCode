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
        
        // mydeleteNode(root,key);
        // return root;

        //https://leetcode-cn.com/problems/delete-node-in-a-bst/solution/miao-dong-jiu-wan-shi-liao-by-terry2020-tc0o/
    if (root == nullptr)    return nullptr;
        if (key > root->val)    root->right = deleteNode(root->right, key);     // 去右子树删除
        else if (key < root->val)    root->left = deleteNode(root->left, key);  // 去左子树删除
        else    // 当前节点就是要删除的节点
        {
            if (! root->left)   return root->right; // 情况1，欲删除节点无左子
            if (! root->right)  return root->left;  // 情况2，欲删除节点无右子
            TreeNode* node = root->right;           // 情况3，欲删除节点左右子都有 
            while (node->left)          // 寻找欲删除节点右子树的最左节点
                node = node->left;
            node->left = root->left;    // 将欲删除节点的左子树成为其右子树的最左节点的左子树
            root = root->right;         // 欲删除节点的右子顶替其位置，节点被删除
        }
        return root;    
    }
};
// @lc code=end

