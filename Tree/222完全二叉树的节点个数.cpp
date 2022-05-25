/* ************************************************************************
> File Name:		222完全二叉树的节点个数.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-25 14:03:31
> Link:		https://leetcode.cn/problems/count-complete-tree-nodes/
> Description:		给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。z
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNodes(TreeNode* root) {
        //递归
        if(!root) return 0;
        else return 1+countNodes(root->left)+countNodes(root->right);

        //上面没有利用完全二叉树的性质
        /**
        完全二叉树的高度可以直接通过不断地访问左子树就可以获取
        判断左右子树的高度: 
        如果相等说明左子树是满二叉树, 然后进一步判断右子树的节点数(最后一层最后出现的节点必然在右子树中)
        如果不等说明右子树是深度小于左子树的满二叉树, 然后进一步判断左子树的节点数(最后一层最后出现的节点必然在左子树中)
        **/
        if(!root) return 0;
        int ldep=getDepth(root->left),rdep=getDepth(root->right);
        if(ldep==rdep) return  1+(1<<ldep)-1+countNodes(root->right);
        else return 1+(1<<rdep)-1+countNodes(root->left);
 
    }
};