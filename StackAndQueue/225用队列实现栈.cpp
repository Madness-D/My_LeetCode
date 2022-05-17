/* ************************************************************************
> File Name:		225用队列实现栈.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-17 21:38:13
> Link:		https://leetcode.cn/problems/implement-stack-using-queues/
> Description:		请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;
//这里的q2仅是在pop及top操作时，备份其余数据
class MyStack {
    queue<int> q1,q2;
    public:
    MyStack() {

    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int t=q1.front();
        q1=q2;
        while(!q2.empty()) q2.pop();
        return t;
    }
    
    int top() {
        int t=pop();
        q1.push(t);
        return t;
    }
    
    bool empty() {
        return q1.empty();
    }
};

//优化，只使用一个队列
//弹出的时候，将将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
class MyStack2 {
    queue<int> qu;
public:
    MyStack() {

    }
    
    void push(int x) {
        qu.push(x);
    }
    
    int pop() {
        int len=qu.size();
        len--;
        while(len--){
            qu.push(qu.front());
            qu.pop();
        }
        int t=qu.front();
        qu.pop();
        return t;
    }
    
    int top() {
        int t=pop();
        qu.push(t);
        return t;
    }
    
    bool empty() {
        return qu.empty();
    }
};