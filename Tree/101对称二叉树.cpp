/* ************************************************************************
> File Name:		101对称二叉树.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-25 13:09:37
> Link:		https://leetcode.cn/problems/symmetric-tree/
> Description:		给你一个二叉树的根节点 root ， 检查它是否轴对称。
> 思路：        递归，写一个辅助的递归函数，判断子树是否对称
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isSymmetric(TreeNode* r1,TreeNode* r2){
        if(!r1 && !r2) return true;
        else if(r1 && r2){
            if(r1->val!=r2->val) return false;
            else return isSymmetric(r1->left, r2->right) && isSymmetric(r1->right, r2->left);
        }
        else return false;
    }
public:
     bool isSymmetric(TreeNode* root) {
        // if(!root) return true;
        // return isSymmetric(root->left, root->right);

        //迭代，这里用的队列，其实用栈、数组都可以
        if(!root) return true;
        queue<TreeNode*> qu;
        qu.push(root->left);
        qu.push(root->right);
        while(!qu.empty()){
            TreeNode* l=qu.front();
            qu.pop();
            TreeNode* r=qu.front();
            qu.pop();
            if(!l && !r) continue;
            else if(!l ||!r||l->val!=r->val) return false;
            qu.push(l->left);
            qu.push(r->right);
            qu.push(l->right);
            qu.push(r->left);
        }
        return true;
    }
};