/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */

// @lc code=start
class Solution {
public:
    string removeOuterParentheses(string s) {
        //遍历一遍,标记一下层数
        //再遍历一遍,把1层的删去
        //但是这样的话,标记结果要存一下,最后遍历删除还需要额外的空间
        //但也不是不行,试一试
        int d=0;
       // vector<int> flag;
        string res;
        for(char ch:s){
            if(ch=='('){
                ++d;
                if(d!=1) res.push_back(ch);
               // flag.push_back(d);
            }else{
               // flag.push_back(d);
               if(d!=1) res.push_back(ch);
                --d;
            }
        }
        
        // for(int i=0;i<s.size();i++){
        //     if(flag[i]!=1){
        //         res=res+s[i];
        //     }
        // }
        return res;


    }
};
// @lc code=end

