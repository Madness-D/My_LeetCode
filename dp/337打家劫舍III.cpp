/* ************************************************************************
> File Name:		337打家劫舍III.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-23 15:44:08
> Link:		https://leetcode.cn/problems/house-robber-iii/
> Description:		树形结构
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> robTree(TreeNode* root){
        //递归返回值为一个长度为2的数组，dp， dp[0]和dp[1]分别表示不偷和偷该节点得到的最大金钱
        //递归边界
        if(!root) return {0,0};
        vector<int> left=robTree(root->left);
        vector<int> right=robTree(root->right);
        //偷root
        int v1=root->val+left[0]+right[0];

        //不偷root，则对于左子节点和右子节点，则可以偷也可以不偷（并不一定要偷）
        int v2=max(left[0],left[1])+max(right[0],right[1]);
        return {v2,v1};
    }
public:
    int rob(TreeNode* root) {
        //不相连的房子。但是是树状的
        //一个节点，如果左节点或右节点选了，就不能选该节点
        //后序遍历，递归
        vector<int> ans=robTree(root);
        return max(ans[0],ans[1]);
        
    }
};