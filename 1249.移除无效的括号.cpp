/*
 * @lc app=leetcode.cn id=1249 lang=cpp
 *
 * [1249] 移除无效的括号
 */

// @lc code=start
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //字母是不需要动的
        //),如果前面有对应的（，也可以保留  第二次遍历的时候需要一个lnum记录（的数目，匹配了就--
        //对于（，如何得知后面还有没有）？ 先遍历一次，rnum记录）的个数，第二次遍历的时候遇到）就--

        int lnum=0,rnum=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){rnum++;}
        }

        string res;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(rnum>0){//表明后面有可以匹配的)
                    res+=s[i];
                    lnum++;//记录(个数
                    rnum--; 
                }  
            }
            else if(s[i]==')'){
                if(lnum<=0){//前无(，不合法，不存入res
                    rnum--;
                    //s.erase(i,1);
                    //lnum=0;
                } else{
                    res+=s[i];
                    lnum--;//消耗前面的(
                }              
            }
            else{
                res+=s[i];
            }
        
        }
        return res;

    }
};
// @lc code=end

