/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] 分割平衡字符串
 */

// @lc code=start
class Solution {
public:
    int balancedStringSplit(string s) {
        int len=s.size();
        if(len==1) return 0;
        int ans=0,sum=1;
        for(int i=1;i<len;i++){
            if(s[i]==s[0]){sum++;}
            else{sum--;}
            if(sum==0){ans++;}
        }
    return ans;

    }
};
// @lc code=end

