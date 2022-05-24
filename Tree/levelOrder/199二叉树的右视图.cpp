/* ************************************************************************
> File Name:		199二叉树的右视图.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-24 21:27:47
> Link:		https://leetcode.cn/problems/binary-tree-right-side-view/
> Description:		给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
>思路：     层序遍历，循环时判断一下到每一层的最后一个时记录下来
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<int> ans;
        if(!root) return ans;
        qu.push(root);
        while(!qu.empty()){
            int len=qu.size();
            for(int i=0;i<len;i++){
                TreeNode* t=qu.front();
                if(i==len-1) ans.emplace_back(t->val);
                if(t->left) qu.push(t->left);
                if(t->right) qu.push(t->right);
                qu.pop();
        }
    }
    return ans;
    }
};