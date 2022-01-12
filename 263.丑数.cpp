/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int n) {
        if(n<1) return false;
        while(!(n%5)){
            n/=5;
        }
        while(!(n%3)){
            n/=3;
        }
        while(!(n%2)){
            n/=2;
        }
        return n==1;
    }
};
// @lc code=end

