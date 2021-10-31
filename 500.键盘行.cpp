/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */

// @lc code=start
class Solution {
public:
    bool isLegal(string s){
        vector<unordered_set<char>> st(3);
        //unordered_set<char> st1,st2,st3;
        st[0]={'q','w','e','r','t','y','u','i','o','p','Q','W','E','R','T','Y','U','I','O','P'};
        st[1]={'A','S','D','F','G','H','J','K','L','a','s','d','f','g','h','j','k','l'};
        st[2]={'Z','X','C','V','B','N','M','z','x','c','v','b','n','m'};
        int flag;
        if(st[0].count(s[0])){flag=0;}
        else if(st[1].count(s[0])){flag=1;}
        else flag=2;

        for(char ch:s){
            if(!st[flag].count(ch)) return false;
        }
        return true;
    }

    vector<string> findWords(vector<string>& words) {
        //qwertyuiop
        //asdfghjkl
        //zxcvbnm
        vector<string> res;
        for(string str:words){
            if(isLegal(str)) res.push_back(str);
        }
        return res;
    }
};
// @lc code=end

