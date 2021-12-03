/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        //调用库函数捏
        //return num==((int)sqrt(num)*(int)sqrt(num));

        // if(num==1) return true;
        // int left=1,right=num;
        // int mid=left+(right-left)/2;
        // while(left<=right){//这里应该是=号
        //     if((long)mid*mid==num){
        //         return true;
        //     }
        //     else if((long)mid*mid<num){
        //         left=mid+1;
        //         mid=left+(right-left)/2;
        //     }
        //     else{
        //         right=mid-1;
        //         mid=left+(right-left)/2;
        //     }
        // }
        // return false;

        // //暴力
        // long x=1,squa=1;
        // while(squa<=num){
        //     squa=x*x;
        //     if(squa==num)
        //         return true;
        //     x++;
        // }
        // return false;

 
        int l=1,r=num;
        while(l<=r){
            int mid=l+(r-l)/2;
            //用double, 防止因为四舍五入出错了
            if((double)num/mid==mid) return true;
            else if(num/mid>mid) l=mid+1;
            else r=mid-1;
        }
        return false;
    
    }
};
// @lc code=end

