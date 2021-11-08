/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        int A=0,sumAB=0;
        vector<int> se(10);
        vector<int> gu(10);
        for(int  i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){ A++;}
            se[secret[i]-'0']++;
            gu[guess[i]-'0']++;
        }
        for(int i=0;i<10;i++){
            sumAB+=min(se[i],gu[i]);
        }
        string res=to_string(A)+"A"+to_string(sumAB-A)+"B";
        return res;

    }
};
// @lc code=end

