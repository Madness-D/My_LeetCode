/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        // int res=0;
        // while(n){
        //     res+=n%2;
        //     n/=2;
        // }
        // return res;
        
        //与2^i做按位与运算，如果第i位为1则结果不为0
        // int res=0;
        // for(int i=0;i<32;i++){
        //     if(n&(1<<i)){res++;}
        // }
        // return res;

        //优化，n&(n-1)，将n的最低位的1置0
        //这样的话，只需做k次，k为1的个数
        int res=0;
        while(n){
            n&=n-1;
            res++;
        }
        return res;

    }
};
// @lc code=end

