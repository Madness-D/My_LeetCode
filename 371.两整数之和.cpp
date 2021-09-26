/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

// @lc code=start
class Solution {
public:
//a + b的问题拆分为(a和b的无进位结果)+(a和b的进位结果)
//无进位加法使用异或运算计算得出          a^b
//进位结果使用与运算和移位运算计算得出.   (a&b)<<1
//循环此过程，直到进位为0

//举个例子，4+5；a==4==0100，b==5==0101； a^b=0001，a&b=0100，（a&b）<<1=1000; 结果1000^0001=1001=9

    int getSum(int a, int b) {
        while (b != 0) {
            //使用无符号整型来防止溢出。当我们赋给无符号类型一个超出它表示范围的值时，结果是初始值对无符号类型表示数值总数取模的余数

            //carry记录 进位结果
            unsigned int carry = (unsigned int)(a & b) << 1;
            //a^b，为无进位加法结果
            a = a ^ b;
            b = carry;
        }
        return a;

    }
};
// @lc code=end

