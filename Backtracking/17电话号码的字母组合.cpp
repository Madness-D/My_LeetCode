/* ************************************************************************
> File Name:		17电话号码的字母组合.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-15 09:46:17
> Link:		https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
> Description:		给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> ans;
    string path;
    string lettermap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
public:
    void backtracking(const string & digits,int startIdx){
        if(path.size()==digits.size()){
            ans.emplace_back(path);
            return;
        }
        int num=digits[startIdx]-'0';
        string s=lettermap[num];
        for(int i=0;i<s.size();i++){
            path.push_back(s[i]);
            backtracking(digits, startIdx+1);
            path.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        backtracking(digits, 0);
        return ans;

    }
};