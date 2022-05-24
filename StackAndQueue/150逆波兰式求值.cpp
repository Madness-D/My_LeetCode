/* ************************************************************************
> File Name:		150逆波兰式求值.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-24 14:18:27
> Link:		https://leetcode.cn/problems/evaluate-reverse-polish-notation/
> Description:		根据逆波兰表示法，求表达式的值。两个整数之间的除法只保留整数部分。
> 思路：        栈，数字则入栈，遇到操作符则
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isNumber(string &s){
        return !(s=="+"||s=="-"||s=="*"||s=="/");
    }
public:
 int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string &s:tokens){
            if(isNumber(s)) st.push(stoi(s));
            else{
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                if(s=="+") n2+=n1;
                else if(s=="-") n2-=n1;
                else if(s=="*") n2*=n1;
                else if(s=="/") {n2/=n1;}
                st.push(n2);
            }
        }
        return st.top();
    }
};

int main(){
    vector<string> vt1={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    Solution sol;

    cout<<sol.evalRPN(vt1)<<endl;

}