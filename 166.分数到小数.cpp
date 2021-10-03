/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
class Solution {
public:
    //使用long long,来避免溢出的情况
    string fractionToDecimal(int numerator, int denominator) {
        long long n=numerator,d=denominator;
        string res;

        if(n*d<0) res+='-';//异号,前面＋一个负号
        //a为整数部分
        long long a=n/d;
        a=a<0?-a:a;//前面已经有符号了,这里转化为正数
        res+=to_string(a);

        //同理,转换为正数
        n=n<0?-n:n;
        d=d<0?-d:d;

        //计算小数部分
        n%=d;
        //能够整除
        if(n==0){
            return res;
        }
        res+='.';

        //连除,利用哈希表来记录是否出现循环
        //哈希表记录每次做除法所用的被除数以及上一次出现的位置
        unordered_map<int,int> st;
        string t;
        int index=0;
        while(n && !st.count(n)){
            st[n] = index++;
            n *= 10;
            t.push_back((char)(n / d + '0'));
            n %= d;
        }
        if(n){
            res+=t.substr(0,st[n])+"("+t.substr(st[n])+")";
        }else{
            res+=t;
        }
        return res;
    }
};
// @lc code=end

