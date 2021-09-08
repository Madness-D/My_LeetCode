/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        int a=0,b=1;
        if(n==0) return a;
        if(n==1) return b;
        for(int i=1;i<n;i++){
            int temp=a+b;
            a=b;
            b=temp;
        }
        return b;

    }
};
// @lc code=end

