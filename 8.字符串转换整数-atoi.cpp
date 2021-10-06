/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};


class Solution {
public:
//忽视前导空格
//如果第一个有效字符，不是正负号或者数字，返回0
    int myAtoi(string s) {
        /*

        //遍历,不使用库函数
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

        ////错误
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

        */

       //官方题解,确定有限状态机
       //https://leetcode-cn.com/problems/string-to-integer-atoi/solution/python3-you-xian-zhuang-tai-zi-dong-ji-b-rq6e/
       //状态:start end 符号 数字
       //转移条件: 空格 符号 数字 其他 
       //不断遍历s,基于当前的字符取更新下一个状态,更新数字位和符号位
        //看不懂,直接复制粘贴了
        Automaton automaton;
        for (char c : s)
            automaton.get(c);
        return automaton.sign * automaton.ans;

    }
};
// @lc code=end

