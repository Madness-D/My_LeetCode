/*
 * @lc app=leetcode.cn id=319 lang=cpp
 *
 * [319] 灯泡开关
 */

// @lc code=start
class Solution {
public:
    int bulbSwitch(int n) {
        //i=1,全开
        //i=2,  1 3 5...灭
        //
        //i=n

        // //对于第j(0开始)个灯,如果(j+1)的因数(1,2,...n)是奇数个,则亮,否则暗
        // //如n=3, 1=1, 2=1,2; 3=1,3 因此只有1亮
        // //超时了,艹
        // int res=0;
        // for(int i=1;i<=n;i++){
        //     int flag=0;
        //     for(int j=1;j<=n;j++){
        //         if(i%j==0) flag++;
        //     }
        //     if(flag%2!=0) res++;
        // }
        // return res;


        //又根据「约数」的定义，我们知道如果某个数k为x的约数，那么x/k亦为x的约数，
        //即「约数」总是成对出现，
        //那么某个数的约数个数为奇数，意味着某个约数在分解过程中出现了2次，
        //且必然重复出现在同一次拆解中，即k=x/k, 
        //即有x为完全平方数（反之亦然）。
        //问题最终转换为：在 [1,n]中完全平方数的个数为多少
        //根据数论推论，[1,n]中完全平方数的个数为sqrt(n)向下取整
        return (int)sqrt(n);
    }
};
// @lc code=end

