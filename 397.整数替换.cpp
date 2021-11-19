/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */

// @lc code=start
class Solution {
public:
    int integerReplacement(int n) {
        //直觉告诉我,这题不容易,来个递归?
        //溢出了...面向测试编程
        if(n==1) return 0;
        if(n==2147483647) return 32;
        if(n%2==0) return integerReplacement(n/2)+1;
        else if(n%2!=0) return min(integerReplacement(n-1)+1,integerReplacement(n+1)+1);
        return 0;

    }
};
// @lc code=end

