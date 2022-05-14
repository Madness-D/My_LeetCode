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
        // string ans;
        // for(char c:s){
        //     if(c!=' ') ans.push_back(c);
        //     else{ans+="%20";}
        // }
        // return ans;

        //先预先给数组扩容带填充后的大小，然后在从后向前进行操作。
        //优点： 无需额外空间、避免顺序操作时移动后续所有元素的操作
        int cnt0=0;
        for(char c:s){
            if(c==' ') cnt0++;
        }
        int oldSize=s.size();
        int newSize=oldSize+2*cnt0;
        s.resize(newSize);
        for(int r=s.size()-1,l=oldSize-1; l>=0;l--,r--){
            if(s[l]!=' '){
                s[r]=s[l];
            }else{
                s[r--]='0';
                s[r--]='2';
                s[r]='%';
            }
        }
        return s;
    }
};