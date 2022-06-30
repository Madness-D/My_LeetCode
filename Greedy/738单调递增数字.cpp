/* ************************************************************************
> File Name:		738单调递增数字.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-27 20:50:13
> Link:		https://leetcode.cn/problems/monotone-increasing-digits/
> Description:		给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     int monotoneIncreasingDigits(int n) {
        //贪心，找最大，则尽量不动最高位
        //找到第一个不符合递增规律的，然后将该位-1，将之后的低位都变成9
        //但-1后可能导致前面的位数不再符合要求，需要再往前倒推
        string s=to_string(n);
        int pos=1;
        while(pos<s.size() && s[pos-1]<=s[pos]) pos++;

        if(pos<s.size()){
            //再往前倒推
            //
            while(pos>0 && s[pos-1]>s[pos]) {s[pos-1]-=1;pos--;}
            
            for(pos+=1;pos<s.size();pos++){
                s[pos]='9';
            }
        }
        return stoi(s);
    }
};