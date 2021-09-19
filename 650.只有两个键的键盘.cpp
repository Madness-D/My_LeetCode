/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 只有两个键的键盘
 */

// @lc code=start
class Solution {
public:
 /*判断是否为质数*/
    bool is_pri(int n){
        int t =sqrt(n);
        for(int i=2;i<=t;i++)
            if(n%i==0)    return false;
        return true;
    }
    int minSteps(int n) {
        //我知道是dp,但不知道怎么搞
        //数学基础,如果是质数,则只能通过1不断叠加//为什么捏,因为粘贴只能是粘贴上一次复制的字符
        //如果不是质数,找到自大的因数i，然后，=minStep(i)+n/i ，n/i是复制粘贴操作次数

        if(n==1)  return 0; 
        if(is_pri(n))    return n;//质数
        else{
            for(int i=n-1;i>0;i--){
                if(n%i==0){//找到最大的因数
                    return minSteps(i)+n/i;
                }
            }
        }
        return 0;

        // if(n&1){    // 判断奇偶
        //     if(is_pri(n))    return n;  // 如果是质数直接返回
        //     int t=sqrt(n);
        //     for(int i=t;i>=3;i--)   // 找到最大的因数
        //         if(n%i==0)
        //             return minSteps(i) + minSteps(n/i);
        // }else return minSteps(n/2) +2;  // 偶数则减半然后加复制黏贴共两次操作
        // return 0;

    }
};
// @lc code=end

