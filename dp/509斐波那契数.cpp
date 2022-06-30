/* ************************************************************************
> File Name:		509斐波那契数.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-30 20:18:42
> Link:		https://leetcode.cn/problems/fibonacci-number/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
         if(n<2) return n;
         int p=0,q=1;
         int t=0;
         for(int i=2;i<=n;i++){
             t=p;
             p=q;
             q=t+p;
             //cout<<q<<endl;
         }
         return q;
    }
};