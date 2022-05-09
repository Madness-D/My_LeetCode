/* ************************************************************************
> File Name:		202快乐数.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-09 23:32:36
> Link:		https://leetcode.cn/problems/happy-number/
> Description:		编写一个算法来判断一个数 n 是不是快乐数。
「快乐数」 定义为：
        对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
        然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
        如果这个过程 结果为 1，那么这个数就是快乐数。
        如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
> 思路： 如果出现循环则不是快乐数，怎么判断循环？ 哈希集合
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int fun(int n){ //获取各位平方和
        int ans=0;
        while(n){
            ans+=(n%10)*(n%10);
            n/=10;
        }
        return ans;
    }
    bool isHappy(int n) {
        //如果出现循环则不会变到1
        unordered_set<int> st;
        while(n!=1){
            if(st.count(n)) return false;
            else{
                st.insert(n);
                n=fun(n);
            }
        }
        return true;
    }
    
};