/* ************************************************************************
> File Name:		131分割回文串.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-15 14:15:40
> Link:		https://leetcode.cn/problems/palindrome-partitioning/
> Description:		给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>> ans;
    vector<string> path;
public:
    void backtracking(const string & s, int idx){//要不要增加记录上一个边界？
        //回溯边界
        if(idx>=s.size()){
            ans.emplace_back(path);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(!isPalindrome(s, idx, i)) continue;
            else{//已经是
                path.emplace_back(s.substr(idx,i-idx+1));
                backtracking(s, i+1);
                path.pop_back();
            }
        }

    }
    //判读是否为回文串
    bool isPalindrome(const string &s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        //回溯递归，切割之后如果左侧是回文，则push进path，递归处理右边
        //如果左侧不是回文，则剪枝
        backtracking(s, 0);
        return ans;
    }
};