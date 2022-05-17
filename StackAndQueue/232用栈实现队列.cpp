/* ************************************************************************
> File Name:		232用栈实现队列.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-17 21:14:45
> Link:		https://leetcode.cn/problems/implement-queue-using-stacks/
> Description:		请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）
只能使用标准的栈操作，也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的

> 思路：        双栈，一个用于输入，一个用于输出
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> st1,st2;
public:
    MyQueue() {
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int t=st2.top();
        st2.pop();
        return t;
    }
    
    int peek() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int t=st2.top();
        return t;
    }
    
    bool empty() {
        return st1.empty()&&st2.empty();
    }
};