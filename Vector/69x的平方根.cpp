/* ************************************************************************
> File Name:     69x的平方根.cpp
> Author:        bwding
>  mail:         dingbuowen@outlook.com
> Created Time:  Thu 28 Apr 2022 02:24:44 PM CST
> link:          https://leetcode-cn.com/problems/sqrtx/
> 问题：         给你一个非负整数 x ，计算并返回 x 的 算术平方根 。返回整数。
> 思路：         二分法，首先知道对于x>1 则sqrtx<=x/2,则可以缩小二分查找的范围
 ************************************************************************/
class Solution {
public:
    int mySqrt(int x) {
        //sqrt(x)<=x/2 x>=4
        if(x==0) return 0;
        else if(x<4) return 1;
        else{
            int l=1,r=x/2;
            while(l<=r){
            int mid=(r-l)/2+l;
            //改用除法来避免mid*mid溢出
            if(mid<=x/mid ) l=mid+1; 
            else r=mid-1;
            }
            return r;
            //return l-1；
        }
    }
};


