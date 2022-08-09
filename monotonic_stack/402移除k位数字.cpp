/* ************************************************************************
> File Name:		402移除k位数字.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-08-09 17:03:43
> Link:		https://leetcode.cn/problems/remove-k-digits/
> Description:		给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，使得剩下的数字最小。请你以字符串形式返回这个最小的数字。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int len=num.size();
        if(len<=k) return "0";
        // //遍历，如果该数字大于后序数字则删除
        // while(k--){
        //     for(int i=0;i<num.size();i++){
        //         if(num[i]>num[i+1]) {num.erase(i,1);break;}
        //     }
        // }
        // while(num[0]=='0'){
        //     num.erase(0,1);
        // }
        // return num==""?"0":num;

        //上面的代码超时，单调栈
        int remain=len-k;
        string ans;
        //这里模仿栈
        for(char c:num){
            while(k && !ans.empty() && ans.back()>c){ //删除大于后序数字的元素
                ans.pop_back();
                k--;
            }
            ans.push_back(c);
        }
        //如112，经过过滤后保留的字符可能过多
        ans.resize(remain);

        //去除前导0
        while(ans[0]=='0'){
            ans.erase(0,1);
        }
        return ans==""?"0":ans;
    }
};