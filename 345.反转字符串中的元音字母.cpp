/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
//a e i o u
class Solution {
public:
    bool isVowels(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){return true;}
        //大写字母
        else return false;
    }
    string reverseVowels(string s) {
        int len=s.size();
        int l=0,r=len-1;
        while(l<r){
            if(!isVowels(s[l])){l++;}
            if(!isVowels(s[r])){r--;}
            if(isVowels(s[l])&&isVowels(s[r])){swap(s[l],s[r]);l++;r--;}
        }
        return s;

    }
};
// @lc code=end

