/*
 * @lc app=leetcode.cn id=1318 lang=cpp
 *
 * [1318] 或运算的最小翻转次数
 */

// @lc code=start
class Solution {
public:
//可以用x&(1<<k)来判断x二进制表示的第k位(最低位为第0位是否为1
//用(x >> k)&1得到x二进制表示的第k位(最低位为第0位）
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < 31; ++i) {
            int bit_a = (a >> i) & 1;//a的第i位
            int bit_b = (b >> i) & 1;//b的第i位
            int bit_c = (c >> i) & 1;//c的第i位
            if (bit_c == 0) {//a和b的最i位都要是0
                ans += bit_a + bit_b;//翻转次数即a,b第i位为1的数目
            }
            else {//a,b有一个为1即可,则同时为0的话,+1,
                ans += (bit_a + bit_b == 0);
            }
        }
        return ans;
    }
};
// @lc code=end

