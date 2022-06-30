/* ************************************************************************
> File Name:		763划分字母区间.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-27 20:10:02
> Link:		https://leetcode.cn/problems/partition-labels/
> Description:		字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        //26个英文字母，遍历记录起点、重点
        int a[26];  
        for(int i=0;i<s.size();i++){  
            a[s[i]-'a']=i;
        }
        int l=0,r=0;
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            r=max(r,a[s[i]-'a']);
            if(i==r){
                ans.emplace_back(r-l+1);
                l=r+1;
            }
        }
        return ans;

    }
};