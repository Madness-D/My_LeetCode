/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //动态规划,dp[i]表示字符串前i个字符(0～i-1)组成的字符串是否符合要求
        //转移方程,dp[i]=dp[j] && check(s[j,j+1,...i-1])
        //边界条件, 定义dp[0]=true
        //为了实现check,将wordDict存为set
        unordered_set<string> wordDictSet(wordDict.begin(),wordDict.end());
        vector<bool> dp(s.size()+1);
        dp[0]=true;
        //注意dp的i的意义
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<i;j++){
                if(dp[j] && wordDictSet.find(s.substr(j,i-j))!=wordDictSet.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

