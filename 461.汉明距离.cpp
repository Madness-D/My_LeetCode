/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n=x^y;//异或之后，不一样的位就是1

        //再使用191的方法统计1的个数
        int res=0;
        while(n){
            n&=n-1;
            res++;
        }
        return res;

    }
};
// @lc code=end

