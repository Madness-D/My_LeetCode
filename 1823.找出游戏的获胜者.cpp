/*
 * @lc app=leetcode.cn id=1823 lang=cpp
 *
 * [1823] 找出游戏的获胜者
 */

// @lc code=start
class Solution {
public:
    int findTheWinner(int n, int k) {
        //约瑟夫环问题
        //https://www.cnblogs.com/olajennings/p/12601844.html
        int last = 0;
        for (int i = 2; i <= n; i++) {
            last = (last + k) % i;
        }
        return last + 1;
    }
};
// @lc code=end

