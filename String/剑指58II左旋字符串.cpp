/* ************************************************************************
> File Name:		剑指58II左旋字符串.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-13 23:13:09
> Link:		https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
> Description:		字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     string reverseLeftWords(string s, int n) {
        //// substr剪切、拼接
        // string t=s.substr(0, n);
        // s.erase(0, n);
        // s+=t;
        // return s;

        //局部旋转、整体旋转
        reverse(s.begin(),s.begin()+n);
        reverse(s.begin()+n,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};