/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        const int m = word1.size();
        const int n = word2.size();
        //1. 定义状态 dp[i][j]  word1[:i-1] 到 word2[:j-1]的最短编辑距离
        int dp[m+1][n+1];
        //2. 处理 base case,边界条件
        for(int i = 0; i <= max(m,n); ++i)
        {
            if(i <= m)  dp[i][0] = i;//删除word1的所有字符
            if(i <= n)  dp[0][i] = i;//删除word2的所有字符
        }
        //3. 状态转移 
        for(int i = 1; i <= m;++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                //   最后一个字符是否相等？ 相等，不用操作 ： min (删除 word 1[i]的操作数,删除 word[j] 的操作数)                  
                dp[i][j] = word1[i-1] == word2[j-1]? dp[i-1][j-1] : min(dp[i-1][j], dp[i][j-1]) + 1;
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

