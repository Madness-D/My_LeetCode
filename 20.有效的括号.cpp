/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
    int len = s.length();
    stack<char> st;
    bool flag = true;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {//左半边，入栈
            st.push(s[i]);
        }
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (st.empty()) { 
                flag = false; 
                //break; 
                return  flag;
                }
            else {
                flag = fun1(st.top(), s[i]);
                if (flag && !st.empty()) { st.pop(); }
                if (!flag) { break; }
            }
        }
    }
        if(!st.empty()){//flag=false;
        return false;
        }
        
        return flag;

    }

    bool fun1(char a, char b) {
    if (a == '(' && b == ')')
        return true;
    if (a == '[' && b == ']')
        return true;
    if (a == '{' && b == '}')
        return true;
    else
        return false;
}
};
// @lc code=end

