/* ************************************************************************
> File Name:		102层序遍历.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-24 21:21:43
> Link:		https://leetcode.cn/problems/binary-tree-level-order-traversal/
> Description:		给你二叉树的根节点 root ，返回其节点值的层序遍历。（即逐层地，从左到右访问所有节点）
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
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
    return ans;
    }
};