/* ************************************************************************
> File Name:		1047删除字符串的相邻重复项.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-17 23:14:26
> Link:		https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/
> Description:		给出由小写字母组成的字符串S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。在S上反复执行重复项删除操作，直到无法继续删除。

*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        // stack<char> st;
        // for(char c:s){
        //     if(st.empty() || c!=st.top()) st.push(c);
        //     else if(c==st.top()) st.pop();
        // }
        // string ans;
        // while(!st.empty()){
        //     ans=st.top()+ans;
        //     st.pop();
        // }
        // return ans;

        //其实string提供的有push和pop方法，不用额外定义一个栈
        string ans;
        for(char c:s){
            if(ans.empty() || c!=ans.back()) ans.push_back(c);
            else if(c==ans.back()) ans.pop_back();
        }
        return ans;
    }
};