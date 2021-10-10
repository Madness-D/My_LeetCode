/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        // //不用long，会溢出
        // long res=1;
        // while((1+res)*res/2<=n){
        //     res++;
        // }
        // return res-1;

        // long long ns=2*n;
        // long long k=(long long) sqrt(ns);
        // while((1+k)*k/2>n){
        //     k--;
        // }
        // return k;
        return ((sqrt((long long) 8 * n + 1) - 1) / 2);

    }
};
// @lc code=end

