/* ************************************************************************
> File Name:		383赎金信.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-09 23:44:34
> Link:		https://leetcode.cn/problems/ransom-note/
> Description:		给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。magazine 中的每个字符只能在 ransomNote 中使用一次。

对于只有小写字母的情况，直接用数组作为哈希表更节省空间
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mp[26]={0};
        for(char c:magazine){
            mp[c-'a']++;
        }
        for(char c:ransomNote){
            if(mp[c-'a']>0) mp[c-'a']--;
            else return false;
        }
        return true;
    }
    
};