/* ************************************************************************
> File Name:		108有序数组构造平衡二叉搜索树.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-08 21:36:12
> Link:		https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/
> Description:		给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。

高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

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
public:
     TreeNode* helpfun(vector<int> & nums, int l,int r){
        if(r<l) return nullptr;
        if(l==r) return new TreeNode(nums[l]);
        int interIdx=(l+r)/2;
        TreeNode* root=new TreeNode( nums[interIdx] );
        root->left=helpfun(nums,l,interIdx-1);
        root->right=helpfun(nums,interIdx+1,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    //焯，AVL树
    //如何保证高度平衡？
    //因为大家默认都是从数组中间位置取值作为节点元素，一般不会随机取，所以想构成不平衡的二叉树是自找麻烦
    return helpfun(nums,0, nums.size()-1);
    }
};

