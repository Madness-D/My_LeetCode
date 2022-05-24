/* ************************************************************************
> File Name:		429N叉树的层序遍历.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-24 21:35:09
> Link:		https://leetcode.cn/problems/n-ary-tree-level-order-traversal/
> Description:		给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> qu;
        vector<vector<int>> ans;
        if(!root) return ans;
        qu.push(root);
        while(!qu.empty()){
            int len=qu.size();
            vector<int> vt;
            while(len--){
                Node* t=qu.front();
                vt.emplace_back(t->val);
                for(auto &it:t->children){
                    if(it) qu.push(it);
                }
                qu.pop();
        }
        ans.emplace_back(vt);

    }
    return ans;
    }
};