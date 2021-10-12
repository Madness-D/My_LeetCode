/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        //使用/
        return (dividend==-2147483648&&divisor==-1)? 2147483647: dividend/divisor;
    }
};
// @lc code=end

