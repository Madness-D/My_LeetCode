/* ************************************************************************
> File Name:		151颠倒字符串中的单词.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-13 23:16:36
> Link:		https://leetcode.cn/problems/reverse-words-in-a-string/submissions/
> Description:		给你一个字符串s，颠倒字符串中单词的顺序。返回单词顺序颠倒且单词之间用单个空格连接的结果字符串。
> 思考：        难点在于空格，不允许有前导空格、后置空格、单词间的多余空格
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     string reverseWords(string s) {
        //使用stringstream
        stringstream ss;
        string ans="",temp;
        ss<<s;
        while(ss>>temp){
            ans=" "+ans;
            ans=temp+ans;
        }
        // if(ans!="")
        //     ans.erase(ans.begin());
        ans.erase(ans.size()-1, 1);
        return ans; 

        //todo:双指针
    }
};