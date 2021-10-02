/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution {
public:
    string s="0123456789abcdef";

    string toHex(int num) {
        //如果是负数，利用位运算+2^32
        long long n=num<0?(long long)num+(1ll << 32):num;

        if(n==0) return "0";

        string ret="";
        while(n){
            //如果是+=，最后字符串的顺序是反的
            ret=s[n%16]+ret;
            n/=16;
        }
        return ret;
    }
};
// @lc code=end

