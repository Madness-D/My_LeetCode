/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string fun1(const string& s1,const string& s2){
        int len=min(s1.size(),s2.size());
        int index=0;
        while(index<len && s1[index]==s2[index]){
            index++;
        }
        return s1.substr(0,index);
    }
    string longestCommonPrefix(vector<string>& strs) {
        int len=strs.size();
        if(len==0) return "";
        string res=strs[0];
        for(int i=1;i<len;i++){
            res=fun1(res,strs[i]);
            if(!res.size()) return "";
        }
        return res;

    }
};
// @lc code=end

