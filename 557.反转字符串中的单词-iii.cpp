/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int len=s.length();
        int p1=0,p2=0;
        for(;p2<len;){
            if(s[p2]!=' '){p2++;}
            if(s[p2]==' '||p2==len-1){//最后一个单词
                int temp;
                if(p2==len-1){temp=p2;}
                else{temp=p2-1;}//空格，不交换空格
                while(p1<temp){
                swap(s[p1],s[temp]);
                ++p1;
                --temp;
                }
                p1=p2+1;
                ++p2;
            }
        }
        return s;
    }
};
// @lc code=end

