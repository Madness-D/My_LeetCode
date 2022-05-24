/* ************************************************************************
> File Name:		107层序遍历2.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-24 21:26:39
> Link:		https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
> Description:		给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

>思路：     在102的基础上reverse一下
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
     queue<TreeNode*> qu;
        vector<vector<int>> ans;
        if(!root) return ans;
        qu.push(root);
        while(!qu.empty()){
            int len=qu.size();
            vector<int> vt;
            while(len--){
                TreeNode* t=qu.front();
                vt.emplace_back(t->val);
                if(t->left) qu.push(t->left);
                if(t->right) qu.push(t->right);
                qu.pop();
        }
        ans.emplace_back(vt);

    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};