/* ************************************************************************
> File Name:		654最大二叉树.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-05 16:19:15
> Link:		https://leetcode.cn/problems/maximum-binary-tree/
> Description:		递归构建最大二叉树，即根节点为数组的最大值，最大值左边的子数组构建左子树，右边的数构建右子树
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
    //先来一个暴力的
    TreeNode* helpFun(vector<int>& nums, int l, int r){
        if(l>r) return nullptr;
        int maxval=nums[l],maxidx=l;
        for(int i=l+1;i<=r;i++){
            if(nums[i]>maxval){
                maxval=nums[i];
                maxidx=i;
            }
        }
        TreeNode* root=new TreeNode(maxval);
        root->left=helpFun(nums, l, maxidx-1);
        root->right=helpFun(nums, maxidx+1, r);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int len=nums.size();
        return helpFun(nums, 0, len-1);
    }
};