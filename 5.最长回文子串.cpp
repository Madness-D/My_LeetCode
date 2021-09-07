/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        //一个经典的问题
        //动态规划，复杂度可以达到n^2
        int  n=s.size();

        if(n<2) return s;

        int maxlen=1;
        int begin=0;

        vector<vector<int>> dp(n,vector<int>(n));

        for(int i=0;i<n;i++){//长度为1的串都是回文串
            dp[i][i]=1;
        }

        for(int L=2;L<=n;L++){//L为子串长度
        for(int i=0;i<n+1-L;i++){
            int j=L+i-1;
            
            if(s[i]!=s[j]){
                dp[i][j]=0;
            }else{
                if(j-i<3){//长度为3的如果两端相等则是回文串？
                    dp[i][j]=1;
                }else{
                    dp[i][j]=dp[i+1][j-1];
                }
            }

            if(dp[i][j] && j-i+1>maxlen){
                maxlen=j-i+1;
                begin=i;
            }
        }

        }
        
        return s.substr(begin,maxlen);
    }
};
// @lc code=end

