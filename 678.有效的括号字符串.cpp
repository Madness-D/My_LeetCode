/*
 * @lc app=leetcode.cn id=678 lang=cpp
 *
 * [678] 有效的括号字符串
 */

// @lc code=start
class Solution {
public:
    bool checkValidString(string s) {
        ////这个方法没有考虑到位置关系的限制，通过了60多个用例
        // int res=0;
        // int flag=0;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='('){res++;}
        //     if(s[i]==')'){res--;}
        //     if(s[i]=='*') {flag++;}
        //     if(res<-1) return false;
        // }
        // if(abs(res)<=abs(flag)) return true;
        // else return false;

        //星号有三种处理方式，对应的res分别++ -- 和不变
        //因此考虑设置maxv、minv两个数，分别记录未匹配的左括号的数量
        //如果maxv<0，表明即使所有的星号都作为(，仍有右括号没办法匹配，那么就false了
        //最小值min最小为0，表明刚好匹配，这样遇到*视为空字符串
        //遍历结束后minv应该为0
        int maxv=0,minv=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){maxv++,minv++;}
            if(s[i]==')'){maxv--;minv=max(minv-1,0);}
            if(s[i]=='*') {maxv++,minv=max(minv-1,0);}
            if(maxv<0) return false;
        }
        return minv==0;
    }
};
// @lc code=end

