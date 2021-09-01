/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 * 直接递归，超时
 * 动态规划，滚动数组思想
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1||n==2) return 1;
         int p = 0, q = 0, r = 1, s = 1;
        for (int i = 3; i <= n; ++i) {
            p = q;
            q = r;
            r = s;
            s = p + q + r;
        }
        return s;

    }
};
// @lc code=end

