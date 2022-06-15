/* ************************************************************************
> File Name:		93复原IP地址.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-15 15:20:36
> Link:		https://leetcode.cn/problems/restore-ip-addresses/
> Description:		给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
     vector<string> ans;
    //不新建字符串了，选择在s上面插入
    //string path;

    //第三个参数，记录已经插入几个逗号
    void backtracking(string& s, int idx,int pointNum ){ 
        //回溯终止，pointNum==3
        if(pointNum==3 ) {
            if(isValid(s,idx,s.size()-1)){
            ans.emplace_back(s);}
            return;
        }
        //遍历
        for(int i=idx;i<s.size();i++){
            if(isValid(s, idx, i)){
                s.insert(s.begin()+i+1,'.');
                //注意已经加上一个'.'，因此是i+2
                backtracking(s, i+2, pointNum+1);
                s.erase(s.begin()+i+1);//删除'.'
            }else{
                //不合法之后，后序的也不合法了
                break;
            }
        }
    }
    bool isValid(const string & s,int start,int end){
        //验证是否合法
        //有前导0
        
        if(start>end) return false;//这个是必须的。。。
        if(s[start]=='0' && start<end) return false;
        //题目说了都是整数嗷，别骗我
        int temp=stoi(s.substr(start,end-start+1));
        if(temp>255 || temp<0) return false;
        return true;
    }
public:
     vector<string> restoreIpAddresses(string s) {
        //其实是切割问题。切割成四份，要求每一份都是0～255，且不含前导零

        int len=s.size();
        if(len<4 || len>12) return ans;
        backtracking(s, 0, 0);
        return ans;
    }
};