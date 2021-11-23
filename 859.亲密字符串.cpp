/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 */

// @lc code=start
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!= goal.size()) return false;
        else{
            vector<int> ss(26),gg(26);
            int cnt=0;
            bool flag=false;
            for(int i=0;i<s.size();i++){
                ss[s[i]-'a']++;
                gg[goal[i]-'a']++;
                if(s[i]!=goal[i]) cnt++;
                if(ss[s[i]-'a']>=2) flag=true;
            }
            //如果词频不同则false
            for(int i=0;i<26;i++){
                if(ss[i]!=gg[i]) return false;
            }
            //现在词频相同
            if(cnt==2) return true;
            if(cnt==0 && flag) return true;
            else return false;

        }
    }
};
// @lc code=end

