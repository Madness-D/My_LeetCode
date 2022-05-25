/* ************************************************************************
> File Name:		110平衡二叉树.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-25 15:43:51
> Link:		https://leetcode.cn/problems/balanced-binary-tree/
> Description:		给定一个二叉树，判断它是否是高度平衡的二叉树。本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {

    int getDepth(TreeNode* root){
        if(!root) return 0;
        else return 1+max(getDepth(root->left),getDepth(root->right));
    }

    int getHeight(TreeNode* root){
        if(!root) return 0;
        int lefth=getHeight(root->left);
        int righth=getHeight(root->right);
        //若左右子树不是平衡二叉树，则直接返回-1，中止
        if(lefth==-1 || righth==-1 || abs(lefth-righth)>1) return -1;
        else return 1+max(lefth,righth);
    }
public:
     bool isBalanced(TreeNode* root) {
        ////自上而下递归，会导致高度的重复计算，复杂度为 O(n^2)
        // if(!root) return true;
        // else return isBalanced(root->left)&& isBalanced(root->right) && abs(getDepth(root->left)-getDepth(root->right))<2;
        

        //自底向上的递归，
        return getHeight(root)>=0;
    }
};