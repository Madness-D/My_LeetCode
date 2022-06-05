/* ************************************************************************
> File Name:		617合并二叉树.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-05 16:40:21
> Link:		https://leetcode.cn/problems/merge-two-binary-trees/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* dfs(TreeNode* r1,TreeNode* r2){
        if(!r1 && !r2) return nullptr;
        //增加下面两行，避免在下面递归时需要判断r1和r2是否存在
        if(!r1 && r2) return r2;
        if(!r2 && r1) return r1;
        int r1v=r1?r1->val:0;
        int r2v=r2?r2->val:0;
        TreeNode* root=new TreeNode(r1v+r2v);
        root->left=dfs(r1->left,r2->left);
        root->right=dfs(r1->right,r2->right);
        return root;
    }
public:
        TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }
};