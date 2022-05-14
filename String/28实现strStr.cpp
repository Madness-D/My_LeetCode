/* ************************************************************************
> File Name:		28实现strStr.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-13 23:14:59
> Link:		https://leetcode.cn/problems/implement-strstr/
> Description:		实现 strStr() 函数。给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;

        // //调用substr匹配
        // int len=needle.size();
        // for(int i=0;i<haystack.size();i++){
        //     if(needle==haystack.substr(i,len)) return i;
        // }
        // return -1;

        // //暴力匹配
        // int  n=haystack.size(),m=needle.size();
        // for(int i=0;i+m<=n;i++){ //注意等号
        //     bool flag=true;
        //     for(int j=0;j<m;j++){
        //         if(haystack[i+j]!=needle[j]) {flag=false;break;}
        //     }
        //     if(flag) return i;
        // }
        // return -1;

        //find函数
        return haystack.find(needle,0);

        //todo: KMP
    }
};