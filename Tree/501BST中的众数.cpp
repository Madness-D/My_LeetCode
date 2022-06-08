/* ************************************************************************
> File Name:		501BST中的众数.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-07 10:39:08
> Link:		https://leetcode.cn/problems/find-mode-in-binary-search-tree/
> Description:		给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
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

 bool cmp(pair<int,int> &p1,pair<int,int> &p2){
     return p1.second>p2.second;
 }

class Solution {


    //BST性质：中序遍历之后是有序数组，那么维护一个最大频数 maxfre，再维护一个当前的频数 curfre
    //如果curfre> maxfre 则清空答案数组，如果=则加入答案数组
    //思考，上面那些变量可以设为全局变量也可以设置成函数的参数
    int maxfre=0,curfre=0;
    vector<int> res;
    void dfs(TreeNode* cur,TreeNode* &pre){
        if(cur==nullptr) return;

        dfs(cur->left,pre);

        if(pre==nullptr){ curfre=1;}
        else if(cur->val==pre->val){
            curfre++;
        }else{
            curfre=1;
        }

        if(curfre==maxfre){
            res.emplace_back(cur->val);
        }
         if(curfre>maxfre){
            maxfre=curfre;
            res.clear();
            
            res.emplace_back(cur->val);
        }
        pre=cur;
        dfs(cur->right,pre);

    }

    void dfs(TreeNode* root, unordered_map<int , int > &mp){
        if(!root) return;
        mp[root->val]++;
        dfs(root->left,mp);
        dfs(root->right,mp);
    }
public:
     vector<int> findMode(TreeNode* root) {
        //  //用map记录频率。然后转换成数组，排序
        // unordered_map<int,int> mp;
        // dfs(root,mp);
        // vector<pair<int,int>> vt;
        // for(auto it:mp){
        //     vt.emplace_back(it.first, it.second);
        // }
        // sort(vt.begin(),vt.end(),cmp);
        // vector<int> ans;
        // //ans.emplace_back(vt[0].first);
        // for(auto it:vt){
        //     if(it.second==vt[0].second) ans.emplace_back(it.first);
        // }
        // return ans;

        res.clear();
        TreeNode* pre=nullptr;
        dfs(root,pre);
        return res;

    }
};