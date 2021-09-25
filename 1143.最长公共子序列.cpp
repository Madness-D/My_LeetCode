/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int m = text1.size();
        const int n = text2.size();
        //1. 定义状态 dp[i][j]  word1[:i-1] 到 word2[:j-1]的LCS长度
        int dp[m+1][n+1];
        //2. 处理 base case
        for(int i = 0; i <= max(m,n); ++i)
        {
            if(i <= m)  dp[i][0] = 0;//LCS长度为0
            if(i <= n)  dp[0][i] = 0;//
        }
        //3. 状态转移 
        for(int i = 1; i <= m;++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                //   最后一个字符是否相等？ 相等，+1 ： max (dp[i-1][j], dp[i][j-1])                  
                dp[i][j] = text1[i-1] == text2[j-1]? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

