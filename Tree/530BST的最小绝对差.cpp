/* ************************************************************************
> File Name:		530BST的最小绝对差.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-05 17:11:52
> Link:		https://leetcode.cn/problems/minimum-absolute-difference-in-bst/
> Description:		返回 树中任意两不同节点值之间的最小差值 。
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
    void inOrder(TreeNode * root, vector<int> &num){
        //if(!root) return;
        if(root->left) inOrder(root->left, num);
        num.emplace_back(root->val);
        if(root->right) inOrder(root->right, num);
    }

    //在中序遍历的过程中用 \textit{pre}pre 变量保存前驱节点的值，这样即能边遍历边更新答案，不再需要显式创建数组来保存
    void inOrder(TreeNode* root, int &pre,int &ans){
        if(!root) return;
        inOrder(root->left, pre, ans);
        if(pre<0){
            pre=root->val;
        }else{
            ans=min(ans,root->val-pre);
            pre=root->val;
        }
        inOrder(root->right, pre, ans);
    }

    int getMinimumDifference(TreeNode* root) {
        // vector<int> num;
        // inOrder(root, num);
        // int ans=INT_MAX;
        // for(int i=0;i<num.size()-1;i++){
        //     ans=min(ans,num[i+1]-num[i]);
        // }
        // return ans;

        int pre=-1,ans=INT_MAX;
        inOrder(root, pre, ans);
        return ans;
    }
};