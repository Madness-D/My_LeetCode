/* ************************************************************************
> File Name:		344反转字符串.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-13 19:28:42
> Link:		https://leetcode.cn/problems/reverse-string/
> Description:		编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
> 思路：    直接用reverse函数是耍流氓，所以就遍历swap吧
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int len=s.size(); 
        for(int i=0;i<len/2;i++){
            swap(s[i],s[len-1-i]);
        }
    }
};