/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // //递归
        // if(n<1){return false;}
        // if(n==1){return true;}
        // if(n!=1 && n%2){return false;}
        // else return isPowerOfTwo(n/2);

        //位运算
        //2的幂，表示成2进制，则只有高位一个1
        //n与n-1按位与之后为0
        //return n > 0 && (n & (n - 1)) == 0;
        //n与-n按位与之后，仍未n
        //return n > 0 && (n & (-n)) == n;

        //整数范围内2的幂，最大为2^30
        int BIG = 1 << 30;
        return n > 0 && BIG % n == 0;

    }
};
// @lc code=end

