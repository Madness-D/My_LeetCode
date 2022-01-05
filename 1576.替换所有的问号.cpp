/*
 * @lc app=leetcode.cn id=1576 lang=cpp
 *
 * [1576] 替换所有的问号
 */

// @lc code=start
class Solution {
public:
    string modifyString(string s) {
        //主要难点是要求不能包含连续重复的字符

        int len=s.size();
        ////自己写的ugly代码
        // if(s[0]=='?') {
        //     if(len==1 || s[1]=='?') s[0]='a';
        //     else s[0]=(s[1]-'a'+1)%26+'a';
        // }
        // for(int i=1;i<len-1;i++){
        //     if(s[i]=='?') {
        //         if(s[i-1]!='a' && s[i+1]!='a') s[i]='a';
        //         else if(s[i-1]!='b' && s[i+1]!='b') s[i]='b';
        //         else if(s[i-1]!='c' && s[i+1]!='c') s[i]='c';
        //     }
        // }
        // if(s[len-1]=='?') s[len-1]=(s[len-2]-'a'+1)%26+'a';

        for(int i=0;i<len;i++){
            if(s[i]=='?'){
                for(char ch='a';ch<='c';ch++){
                    //i>0和i<len-1,防止溢出
                    if(i>0 &&s[i-1]==ch || i<len-1 && s[i+1]==ch) continue;
                     s[i]=ch;
                }
            }
        }
        return s;
    }
};
// @lc code=end

