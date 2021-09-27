/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        // //下面的方法错误，没注意到题目要求的必须连续
        // stack<char> st;
        // int res=0;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='('){
        //         st.push(s[i]);
        //     }else{
        //         if(st.empty()) continue;
        //         else{ res+=2;st.pop();}
        //     }
        // }
        // return res;

    }
};
// @lc code=end

