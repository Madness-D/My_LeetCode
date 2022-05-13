/* ************************************************************************
> File Name:		剑指05替换空格.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-13 19:47:05
> Link:		https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
> Description:		请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for(char c:s){
            if(c!=' ') ans.push_back(c);
            else{ans+="%20";}
        }
        return ans;
    }
};