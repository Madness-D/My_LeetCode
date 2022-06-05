/* ************************************************************************
> File Name:		513找树左下角的值.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-26 20:03:08
> Link:		https://leetcode.cn/problems/find-bottom-left-tree-value/
> Description:		给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。假设二叉树中至少有一个节点。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int findBottomLeftValue(TreeNode* root) {
        //层序遍历
        queue<TreeNode* > qu;
        qu.push(root);
        int ans;
        while(!qu.empty()){
            ans=qu.front()->val;
            int len=qu.size();
            while(len--){
                TreeNode* t=qu.front();
                if(t->left) qu.push(t->left);
                if(t->right) qu.push(t->right);
                qu.pop();
            }
        }
        return ans;
    }
    
};