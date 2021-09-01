/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {
        int len=s.length();
        int ab=0,la=0;
        for(int i=0;i<len;i++){
            if(s[i]=='A'){
                ab++;
                if(ab>=2){
                    return false;
                    }
            }
            if(s[i]=='L'){
                if(i<=len-3 && s[i+1]=='L' && s[i+2]=='L'){
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

