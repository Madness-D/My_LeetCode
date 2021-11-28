/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len1=s.size(),len2=p.size();
        ////错误, 没有考虑到p里面有重复的字符的情况
        // unordered_set<char> us;
        // for(char ch:p){
        //     us.insert(ch);
        // }
        // vector<int> res;
        // int l=0;
        // int r;
        // while(l<len1-len2){
        //     if(us.count(s[l])){
        //         r=l+1;
        //         while(us.count(s[r]) && r<=l-1+len2){r++;}
        //         if(r-l+1==len2) {res.push_back(l);}
        //     }
        //     l=r+1;
        // }
        // return res;

        //先创建一个大小为 26 的数组c2 来统计字符串 p 的词频，
        //另外一个同等大小的数组 c1 用来统计「滑动窗口」内的 s 的子串词频。
        if(len1<len2) return {};

        vector<int> ss(26);
        vector<int> pp(26);
        vector<int> res;

        for(int i=0;i<len2;i++){
            ss[s[i]-'a']++;
            pp[p[i]-'a']++;
        }
        if(ss==pp) res.push_back(0);

        for(int i=0;i<len1-len2;i++){
            ss[s[i]-'a']--;
            ss[s[i+len2]-'a']++;
            if(ss==pp) res.push_back(i+1);
        }
        return res;

    }
};
// @lc code=end

