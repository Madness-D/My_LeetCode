/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        //递归
        if(n%3!=0 && n!=1) return false;
        if(n==2||n<1)return false;
        if(n==3||n==1) return true;
        else return isPowerOfThree(n/3);

        // //在题目给定的 3232 位有符号整数的范围内，最大的3 的幂为 3^{19} = 11622614673 我们只需要判断 n 是否是 3^{19}的约数即可
        // return n > 0 && 1162261467 % n == 0;

    }
};
// @lc code=end

