/* ************************************************************************
> File Name:		20有效的括号.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-17 21:25:04
> Link:		https://leetcode.cn/problems/valid-parentheses/
> Description:		给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     bool isValid(string s) {
        // stack<char> st;
        // for(char c:s){
        //     if(c=='('|| c=='{'||c=='[') st.push(c);
        //     else{
        //         if(st.empty()) return false;
        //         if(c==')' && st.top()=='(') st.pop();
        //         else if(c=='}' && st.top()=='{') st.pop();
        //         else if(c==']' && st.top()=='[') st.pop();
        //         else return false;
        //     }
        // }
        // return st.empty();

        //下面这个方法，遇到左边的括号，将右括号压入栈，之后仅需比较是否相等
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            // 第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
            // 第二种情况：遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop(); // st.top() 与 s[i]相等，栈弹出元素
        }
        // 第一种情况：此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false，否则就return true
        return st.empty();
    }
};