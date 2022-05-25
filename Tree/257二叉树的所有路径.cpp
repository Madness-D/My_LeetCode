/* ************************************************************************
> File Name:		257二叉树的所有路径.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-25 16:55:26
> Link:		https://leetcode.cn/problems/binary-tree-paths/
> Description:		https://leetcode.cn/problems/binary-tree-paths/
> 思路：        典型的回溯
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void travel(TreeNode*root, vector<int> &path,vector<string> & ans){
        path.emplace_back(root->val);
        if(!root->left && !root->right) {//到达DFS的一个尽头，则将当前记录的路径
            string temp;
            for(int i=0;i<path.size()-1;i++){
                temp+=to_string(path[i]);
                temp+="->";
            }
            temp+=to_string(path[path.size()-1]);
            ans.emplace_back(temp);
            //path.pop_back(); //如果这里pop，回溯，可能导致回的不够
        }else {
            if(root->left){
                travel(root->left, path, ans);
                path.pop_back();
            }
            if(root->right){
                travel(root->right,path, ans);
                path.pop_back();
            }
        }
    }

    void dfs(TreeNode* root, string s,vector<string> &ans){
        if(!root) return ;
        s+=to_string(root->val)+"->";
        if(!root->left && !root->right){//到达世界最高城，叶子节点
        s.pop_back();
        s.pop_back();
        ans.emplace_back(s);
        }
        dfs(root->left,s,ans);
        dfs(root->right,s,ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        // //标准的DFS，回溯
        // //递归和回溯就是一家的
        // vector<int> path;
        // vector<string> ans;
        // if(!root) return ans;
        // travel(root, path, ans);
        // return ans;

        vector<string> ans;
        if(!root) return ans;
        dfs(root, "", ans);
        return ans;
    }
};