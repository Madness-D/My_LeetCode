/* ************************************************************************
> File Name:		541反转字符串2.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-13 20:37:02
> Link:		https://leetcode.cn/problems/reverse-string-ii/
> Description:		给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
    如果剩余字符少于 k 个，则将剩余字符全部反转。
    如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        // //每2k，反转前k个
        // int l=0;
        // while(l<s.size()){
        //     int  r=(l+k)>=s.size()?s.size():l+k;
        //     reverse(s.begin()+l, s.begin()+r);
        //     l+=2*k;
        // }
        // return s;

        for(int l=0;l<s.size();l+=2*k){
            reverse(s.begin()+l, s.begin()+min(l+k,(int)s.length()));
        }
        return s;
    }
};