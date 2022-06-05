/* ************************************************************************
> File Name:		106从中序和后序遍历构造二叉树.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-28 15:38:02
> Link:		https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
> Description:		给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

*************************************************************************/
#include<bits/stdc++.h>
using namespace std;


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
/*
第一步：如果数组大小为零的话，说明是空节点了。
第二步：如果不为空，那么取后序数组最后一个元素作为节点元素。
第三步：找到后序数组最后一个元素在中序数组的位置，作为切割点
第四步：切割中序数组，切成中序左数组和中序右数组 （顺序别搞反了，一定是先切中序数组）
第五步：切割后序数组，切成后序左数组和后序右数组
第六步：递归处理左区间和右区间
*/
//可以用哈希表来加快寻找分割点
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int len=inorder.size();
        for(int i=0;i<len;i++){
            mp[inorder[i]]=i;
        }
        return preorder(inorder, postorder, 0, len-1, 0, len-1);
    }
    TreeNode*  preorder(vector<int>& ino, vector<int>& posto,int inl,int inr,int postl, int postr){
        if(inl> inr || postl> postr) return nullptr;
        int rootval=posto[postr];
        TreeNode *root=new TreeNode(rootval); //根节点
        //根据后序的最后一个元素，即根节点，在中序遍历中找到该值
        //这里可以用map来优化
        int rootIdxInorder=inl;
        // while(ino[rootIdxInorder]!=rootval){
        //     rootIdxInorder++;
        // }
        rootIdxInorder=mp[rootval];
        int eleNum=rootIdxInorder-inl;//左子树个数
        root->left=preorder(ino, posto, inl, inl+eleNum-1, postl, postl+eleNum-1);
        root->right=preorder(ino, posto, rootIdxInorder+1, inr, postl+eleNum, postr-1);
        return root;


    }

    
};