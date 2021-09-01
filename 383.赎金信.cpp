/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    //思路：建立两个hash表，然后遍历信的哈希表，只要信里的value>杂志中的同key的value，就false;
    int len1=ransomNote.length(),len2=magazine.length();
    if(len1 > len2) return false;

    // unordered_map<char,int> mp1,mp2;
    // for(int i=0;i<len1;i++){
    //     mp1[ransomNote[i]]++;
    // }
    // for(int i=0;i<len2;i++){
    //     mp2[magazine[i]]++;
    // }

    // unordered_map<char,int>::iterator iter=mp1.begin();
    // for(;iter!=mp1.end();iter++){
    //     if(iter->second > mp2[iter->first]){
    //         return false;
    //     }
    // }

    int ha1[26]={0},ha2[26]={0};

    for(int i=0;i<len1;i++){
        ha1[ransomNote[i]-'a']++;
    }

    for(int i=0;i<len2;i++){
        ha2[magazine[i]-'a']++;
    }

    for(int i=0;i<26;i++){
        if(ha1[i]>ha2[i]) return false;
    }


return true;
    }
};
// @lc code=end

