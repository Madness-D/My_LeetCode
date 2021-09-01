/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 * 思路：[0,c-1]  区间，两数之和，双指针
 * 注意可能溢出，因此用long
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        long  i=0,j=(int)sqrt(c);
        while(i<=j){
            long sum=i*i+j*j;
            if(sum==c)
                return true;
            else if(sum<c)
                i++;
            else    
                j--;          
        }
        return false;

    }
};
// @lc code=end

