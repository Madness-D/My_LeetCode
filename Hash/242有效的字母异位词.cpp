/* ************************************************************************
> File Name:		242有效的字母异位词.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-09 17:03:43
> Link:		https://leetcode.cn/problems/valid-anagram/
> Description:	给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
    注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词
	
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
bool isAnagram(string s, string t) {
        // //如果是异位词，则排序后相等
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return s==t;

        //哈希
        int a[27]={0};
        for(char c:s){
            a[c-'a']++;
        }
        for(char c:t){
            a[c-'a']--;
        }
        for(int n:a){
            if(n!=0) return false;
        }
        return true;
    }

    
};