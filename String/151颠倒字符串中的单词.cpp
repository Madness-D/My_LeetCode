/* ************************************************************************
> File Name:		151颠倒字符串中的单词.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-13 23:16:36
> Link:		https://leetcode.cn/problems/reverse-words-in-a-string/submissions/
> Description:		给你一个字符串s，颠倒字符串中单词的顺序。返回单词顺序颠倒且单词之间用单个空格连接的结果字符串。
> 思考：        难点在于空格，不允许有前导空格、后置空格、单词间的多余空格
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     string reverseWords(string s) {
         string ans="";
        ////使用stringstream
        // stringstream ss;
        // string temp;
        // ss<<s;
        // while(ss>>temp){
        //     ans=" "+ans;
        //     ans=temp+ans;
        // }
        // // if(ans!="")
        // //     ans.erase(ans.begin());
        // ans.erase(ans.size()-1, 1);

        
    /*
        调库函数，sc++没有提供现成的split，可以结合substr和find
        参考博文：https://blog.csdn.net/Mary19920410/article/details/77372828
        find函数
            函数原型：size_t find(const string& str, size_t pos = 0) const;
            功能说明：从pos位置开始查找子字符串str第一次出现的位置
            参数说明：str为要查找的子字符串，pos从为初始查找位置
            返回值：找到的话返回子字符串第一次出现的位置，否则返回string::npos
        substr函数
            函数原型：string substr(size_t pos = 0, size_t n = npos) const;
            功能说明：获取从指定的起始位置开始，长度为n的子字符串
            参数说明：pos为起始位置，n获取的1字符串长度
            返回值：子字符串
    */
        // vector<string> words;
        // s=s+' ';//末尾加上空格，便于分割
        // size_t pos=0;
        // size_t size=s.length();
        // for(int i=0;i<size;i++){
        //     pos=s.find(" ",i);
        //     if(pos<size){
        //         string t=s.substr(i,pos-i);
        //         if(t!=" " && t!="") words.emplace_back(t);
        //         i=pos;
        //     }
        // }
        // reverse(words.begin(),words.end());
        // for(string tt:words){
        //     ans+=tt;
        //     ans+=" ";
        // }
        // ans.erase(ans.size()-1,1);

        //移除多余空格  将整个字符串反转   将每个单词反转
        //再次提醒，erase本身的复杂度为o(n),因此用双指针的方法
        //去除空格和反转部分字符串的功能实现为函数

        removeExtraSpaces(s); //去除多余空格，保证单词之间之只有一个空格，且字符串首尾没空格。
        reverse(s, 0, s.size() - 1);
        int start = 0; //removeExtraSpaces后保证第一个单词的开始下标一定是0。
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
                reverse(s, start, i - 1); //翻转，注意是左闭右闭 []的翻转。
                start = i + 1; //更新下一个单词的开始下标start
            }
        }
        return s;
        //return ans; 
    }

    void reverse(string& s, int start, int end){ //翻转，区间写法：闭区间 []
        for(int i=start,j=end;i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }

    void removeExtraSpaces(string& s) {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
        //整体思想参考Leetcode: 27. 移除元素：https://leetcode-cn.com/problems/remove-element/
        int slow=0;
        for(int fast=0;fast<s.size();fast++){
            if(s[fast]!=' '){
                if (slow != 0) s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
                while(fast<s.size() && s[fast]!=' '){s[slow++]=s[fast++];}
            }
        }
        s.resize(slow);
    }
};