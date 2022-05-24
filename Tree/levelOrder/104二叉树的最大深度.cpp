/* ************************************************************************
> File Name:		104二叉树的最大深度.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-24 23:44:10
> Link:		https://leetcode.cn/problems/maximum-depth-of-binary-tree/
> Description:		给定一个二叉树，找出其最大深度。二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int layer=0;
        if(!root) return layer;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            int len=qu.size();
            for(int i=0;i<len;i++){
                TreeNode* tnode=qu.front();
                if(tnode->left) qu.push(tnode->left);
                if(tnode->right) qu.push(tnode->right);
                qu.pop();
            }
            layer++;
        }
        return layer;
    }
};