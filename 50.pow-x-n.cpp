/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
    //     //超时
    //     if(n==0) return 1;
    //     double res=1;
    //     if(n>0){
    //         n++;
    //         while(n--){
    //             res*=x;
    //         }
    //     }
    //     if(n<0){
    //         while(n++){
    //             res/=x;
    //         }
    //     }
    // return res;

    //return pow(x,n);

    //快速幂，本质是分治的思想
    double res = 1.0;
    for(int i = n; i != 0; i /= 2){
        if(i % 2 != 0){
            res *= x;
        }
        x *= x;
    }
    //如果n是负数，则取倒数
    return  n < 0 ? 1 / res : res;


    }
};
// @lc code=end

