/* ************************************************************************
> File Name:		459重复的子字符串.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-14 00:38:30
> Link:		https://leetcode.cn/problems/repeated-substring-pattern/
> Description:		给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        //设母串S是由子串s重复N次而成， 则S+S则有子串s重复2N次， 那么现在有S=Ns，S+S=2Ns，其中N>=2。 
        //如果条件成立， S+S=2Ns, 掐头去尾破坏2个s，S+S中还包含2*（N-1）s, 又因为N>=2, 因此S在(S+S)[1:-1]中必出现一次以上
        int len=s.length();
        if(len==1) return false;
        string str=s+s;
        //str.erase(0,1);
        str.erase(str.length()-1, 1);
        //string::npos == -1,找不到则返回npos
        return !(str.find(s,1)==string::npos);

        //todo:KMP
        

    }
};