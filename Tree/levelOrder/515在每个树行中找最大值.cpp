/* ************************************************************************
> File Name:		515在每个树行中找最大值.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-24 22:59:01
> Link:		https://leetcode.cn/problems/find-largest-value-in-each-tree-row/
> Description:		给定一棵二叉树的根节点root ，请找出该二叉树中每一层的最大值。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<int> ans;
        if(!root) return ans;
        qu.push(root);
        while(!qu.empty()){
            int len=qu.size();
            int tmin=INT_MIN;
            while(len--){
                TreeNode* t=qu.front();
                tmin=max(tmin,t->val);
                if(t->left) qu.push(t->left);
                if(t->right) qu.push(t->right);
                qu.pop();
        }
        ans.emplace_back(tmin);
        }
        return ans;
    }
};