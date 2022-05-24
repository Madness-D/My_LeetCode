/* ************************************************************************
> File Name:		637二叉树的层平均值.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-24 21:32:14
> Link:		https://leetcode.cn/problems/average-of-levels-in-binary-tree/
> Description:		给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<double> ans;
        if(!root) return ans;
        qu.push(root);
        while(!qu.empty()){
            int len=qu.size();
            double sum=0.0;
            for(int i=0;i<len;i++){
                TreeNode* t=qu.front();
                //if(i==len-1) ans.emplace_back(t->val);
                sum+=t->val;
                if(t->left) qu.push(t->left);
                if(t->right) qu.push(t->right);
                qu.pop();
        }
        ans.emplace_back(sum/len);
    }
    return ans;
    }
};