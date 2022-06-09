/* ************************************************************************
> File Name:		450BST的删除节点.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-08 20:42:58
> Link:		https://leetcode.cn/problems/delete-node-in-a-bst/
> Description:		给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
     TreeNode* deleteNode(TreeNode* root, int key) {
        //先定位到要删除的节点node
        //若node为叶子节点，直接删除
        //若node有左子树而无右子树，直接返回其左子树
        //若只有右子树，直接返回其右子树
        //否则，将右子树中的最小节点newroot作为根节点代替node，同时在右子树中删除该newroot

        if(!root) return root;
        if(root->val>key) root->left=deleteNode(root->left,key);
        else if(root->val<key) root->right=deleteNode(root->right,key);
        else{
            if(!root->left) return root->right;
            else if(!root->right) return root->left;
            else{//左右子节点都存在
                TreeNode* node=root->right;
                while(node->left) node=node->left;
                node->left=root->left;
                root=root->right;
                //root=node;
            }
        }
        return root;

    }
};