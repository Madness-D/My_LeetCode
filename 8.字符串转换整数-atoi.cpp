/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
//忽视前导空格
//如果第一个有效字符，不是正负号或者数字，返回0
    int myAtoi(string s) {
        int len=s.size();
        int index=0;
        //去除前导空格
        while(index<len && s[index]==' '){
            index++;
        }
        if(index==len || (!isdigit(s[index])&&s[index]!='-' && s[index]!='+')) return 0;

        bool nega=false;

        if(s[index]=='+'|| s[index]=='-'){
            if(s[index]=='-'){
                nega=true;
            }
            index++;
        }
        long ans=0;
        while(index<len && isdigit(s[index])){
            ans=ans*10+s[index]-'0';
            index++;
        if(nega && -ans<INT_MIN) return INT_MIN;
        if(!nega && ans>INT_MAX) return INT_MAX;
        }

        return nega?-ans:ans;
        
        // if(s[index]=='-'){
        //     nega=true;
        //     index++;
        // }else if(s[index]=='+'){
        //     nega=false;
        //     index++;
        // }else if(s[index]<='9'&&s[index]>='0'){
        //     nega=false;
        // }else {
        //     return 0;
        // }

        // string str=" ";
        // long ans=0;
        // while(index<len && (s[index]<='9'&&s[index]>='0')){
        //     str+=s[index];
        //     index++;
        // }
        // ans=stol(str);
        // if(nega && -ans<INT_MIN) return INT_MIN;
        // if(!nega && ans>INT_MAX) return INT_MAX;
        // else return nega?-ans:ans;

    }
};
// @lc code=end

