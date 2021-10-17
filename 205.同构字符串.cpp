/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //维护两个哈希表，判断是否为双射关系
        //即，同时遍历s和t，然后将映射关系存入两个哈希表，如果冲突则返回false
        unordered_map<char,char> s2t;
        unordered_map<char,char> t2s;
        for(int i=0;i<s.size();i++){
            char ss=s[i],tt=t[i];
            if((s2t.count(ss)&&s2t[ss]!=tt) || (t2s.count(tt) && t2s[tt]!=ss)){
                return false;
            }
            s2t[ss]=tt;
            t2s[tt]=ss;
        }
        return true;

    }
};
// @lc code=end

