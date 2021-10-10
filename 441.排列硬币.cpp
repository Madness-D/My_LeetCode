/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        long res=1;
        while((1+res)*res/2<=n){
            res++;
        }
        return res-1;

    }
};
// @lc code=end

