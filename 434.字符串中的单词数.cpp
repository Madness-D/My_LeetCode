/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        // //根据空格或者是起始位置，来计数
        // int res=0;
        // for(int i=0;i<s.size();i++){
        //     if((i==0||s[i-1]==' ' )&& s[i]!=' '){
        //         res++;
        //     }
        // }
        // return res;

        //划分单词
        vector<string> v;
        string str;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                str.push_back(s[i]);
            }else if(s[i]==' '){
                if(!str.empty()){
                    v.push_back(str);
                }
                str.clear();
            }
        }
        if(!str.empty()){
                    v.push_back(str);
        }

        return v.size();

    }
};
// @lc code=end

