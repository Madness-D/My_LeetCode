/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */

// @lc code=start
class Solution {
public:
    int findNthDigit(int n) {
        //1     1～9  //9个
        //2     10～99   //90个,2*90个数字
        //3     100～999  //900个 3*900个数字
        // .......
        //k     10^(k-1)～10^k-1    //9*10^(k-1)个数, k*9*10^(k-1)个数字

        int d = 1, count = 9;
        while (n > (long) d * count) {
            n -= d * count;
            d++;
            count *= 10;
        }
        int index = n - 1;
        int start = (int) pow(10, d - 1);
        int num = start + index / d;
        int digitIndex = index % d;
        int digit = (num / (int) (pow(10, d - digitIndex - 1))) % 10;
        return digit;

       


    }
};
// @lc code=end

