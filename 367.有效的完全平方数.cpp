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

        if(num==1) return true;
        int left=1,right=num;
        int mid=left+(right-left)/2;
        while(left<=right){//这里应该是=号
            if((long)mid*mid==num){
                return true;
            }
            else if((long)mid*mid<num){
                left=mid+1;
                mid=left+(right-left)/2;
            }
            else{
                right=mid-1;
                mid=left+(right-left)/2;
            }
        }
        return false;
    }
};
// @lc code=end

