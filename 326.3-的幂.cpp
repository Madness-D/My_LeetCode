/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        // //递归
        // if(n%3!=0 && n!=1) return false;
        // if(n==2||n<1)return false;
        // if(n==3||n==1) return true;
        // else return isPowerOfThree(n/3);

        // //在题目给定的 3232 位有符号整数的范围内，最大的3 的幂为 3^{19} = 11622614673 我们只需要判断 n 是否是 3^{19}的约数即可
        // return n > 0 && 1162261467 % n == 0;

        // //试除法，不断/3
        // while(n && n%3==0){
        //     n/=3;
        // }
        // return n==1;

        //打表
        switch (n) {
		case 1:return true;
		case 3:return true;
		case 9:return true;
		case 27:return true;
		case 81:return true;
		case 243:return true;
		case 729:return true;
		case 2187:return true;
		case 6561:return true;
		case 19683:return true;
		case 59049:return true;
		case 177147:return true;
		case 531441:return true;
		case 1594323:return true;
		case 4782969:return true;
		case 14348907:return true;
		case 43046721:return true;
		case 129140163:return true;
		case 387420489:return true;
		case 1162261467:return true;
		default: return false;
		}
    }
};
// @lc code=end

