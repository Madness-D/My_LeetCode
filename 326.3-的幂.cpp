/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        //递归
        if(n%3!=0 && n!=1) return false;
        if(n==2||n<1)return false;
        if(n==3||n==1) return true;
        else return isPowerOfThree(n/3);

    }
};
// @lc code=end

