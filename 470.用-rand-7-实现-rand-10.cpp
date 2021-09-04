/*
 * @lc app=leetcode.cn id=470 lang=cpp
 *
 * [470] 用 Rand7() 实现 Rand10()
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        //return (rand7()+rand7()+rand7()+rand7()+rand7()+rand7()+rand7()+rand7()+rand7()+rand7())%10+1;

        //和
        int a=rand7(),b=rand7();
        if(a<4 && b>4) return rand10();
        else return (a+b)%10+1;

        // //积
        // int res=rand7()+(rand7()-1)*7;
        // if(res>40) return rand10();
        // else return res%10+1;
        
    }
};
// @lc code=end

