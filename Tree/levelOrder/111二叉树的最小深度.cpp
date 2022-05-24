/* ************************************************************************
> File Name:		111二叉树的最小深度.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-24 23:48:43
> Link:		https://leetcode.cn/problems/minimum-depth-of-binary-tree/
> Description:		给定一个二叉树，找出其最小深度。最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
>思路：     叶子节点，左右节点均为nullptr
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        int layer=0;
        if(!root) return layer;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            layer++;
            int len=qu.size();
            for(int i=0;i<len;i++){
                TreeNode* tnode=qu.front();
                if(!tnode->left && !tnode->right) return layer;
                if(tnode->left) qu.push(tnode->left);
                if(tnode->right) qu.push(tnode->right);
                qu.pop();
            }
            
        }
        return layer;
    }
};