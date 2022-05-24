/* ************************************************************************
> File Name:		117填充每个节点的下一个右侧节点指针2.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-24 23:37:08
> Link:		https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/
> Description:		给定一个二叉树,填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将next指针设置为 NULL。

*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> qu;
        qu.push(root);
        while(!qu.empty()){
            int len=qu.size();
            for(int i=0;i<len;i++){
                Node* tnode=qu.front();
                if(tnode->left) qu.push(tnode->left);
                if(tnode->right) qu.push(tnode->right);
                qu.pop();
                if(i==len-1) tnode->next=nullptr;
                else tnode->next=qu.front();
            }
        }
        return root;
    }
};