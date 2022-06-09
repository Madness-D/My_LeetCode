/* ************************************************************************
> File Name:		114二叉树展开成链表.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-09 16:44:52
> Link:		https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/
> Description:		给你二叉树的根结点 root ，请你将它展开为一个单链表：展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 
展开后的单链表应该与二叉树 先序遍历 顺序相同。
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
    void flatten(TreeNode* root) {
        //将左子树插到右子树的地方
        //将原来的右子树插到左子树的最右边节点
        while(root){
            if(!root->left) root=root->right;
            else{
                //寻找左子树的最右节点
                TreeNode* pre=root->left;
                while(pre->right) pre=pre->right;
                //将右子树连接到pre处
                pre->right=root->right;
                //修改root的左右指针
                root->right=root->left;
                root->left=nullptr;
                root=root->right;
            }
        }
    }
};