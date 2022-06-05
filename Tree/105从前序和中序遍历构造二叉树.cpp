/* ************************************************************************
> File Name:		105从前序和中序遍历构造二叉树.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-05 16:08:38
> Link:		https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
> Description:		给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

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
    unordered_map<int, int> mp;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len=inorder.size();
        for(int i=0;i<len;i++){
            mp[inorder[i]]=i;
        }
        return help(preorder, inorder, 0, len-1, 0, len-1);
    }
    TreeNode*  help(vector<int>& preo, vector<int>& ino,int prel,int prer,int inl, int inr){
        if(inl> inr || prel> prer) return nullptr;
        int rootval=preo[prel];
        TreeNode *root=new TreeNode(rootval); //根节点
        //根据后序的最后一个元素，即根节点，在中序遍历中找到该值
        //这里可以用map来优化
        int rootIdxInorder=prel;
        // while(ino[rootIdxInorder]!=rootval){
        //     rootIdxInorder++;
        // }
        rootIdxInorder=mp[rootval];
        int eleNum=rootIdxInorder-inl;//左子树个数
        root->left=help(preo, ino,prel+1,prel+eleNum,inl,inl+eleNum-1);
        root->right=help(preo, ino,prel+eleNum+1,prer,rootIdxInorder+1,inr);
        return root;
    }
};