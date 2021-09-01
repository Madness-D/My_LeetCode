/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
    int len1=s.length(),len2=t.length();
    if(len1 != len2) return false;

    int ha1[26]={0},ha2[26]={0};

    for(int i=0;i<len1;i++){
        ha1[s[i]-'a']++;
    }

    for(int i=0;i<len2;i++){
        ha2[t[i]-'a']++;
    }

    for(int i=0;i<26;i++){
        if(ha1[i]!=ha2[i]) return false;
    }


    return true;
    }
};
// @lc code=end

