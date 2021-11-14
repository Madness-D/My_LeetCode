/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()<2) return true;
        bool flag2=false;
        //全小写
        if(word[0]>='a'){
            for(char ch:word){
                if(ch<'a') return false;
            }
        }
        else{
            if(word[1]>='a') flag2=true;
            for(int i=2;i<word.size();i++){
                if(!flag2 && word[i]>='a') return false;
                if(flag2 && word[i]<'a') return false;
            }

        }
        return true;
    }
};
// @lc code=end

