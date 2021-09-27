/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        // //如果是0,一定和前一位一起
        // //动态规划,令dp[i]为到第i位的方法总数
        // //显然,dp[i]只与dp[i-1]和dp[i-1]有关
        // //如果s[i]=='0'.而且s[i-1]=='1'或'2',则dp[i]==dp[i-2]
        // //如果s[i-1]==1,则dp[i]=dp[i-1]+dp[i-2],即s[i-1]与s[i]分开和合并的情况
        // //如果s[i-1]=2, '1'<=s[i]<='6',则dp[i]=dp[i-1]+dp[i-2]
        // if(s[0]=='0') return 0;
        // int pre=1,curr=1;//dp[-1]=dp[0]=1;
        // for(int i=1;i<s.size();i++){
        //     int temp=curr;
        //     if(s[i]=='0'){
        //         if(s[i-1]=='1'||s[i-1]=='2'){
        //             curr=pre;
        //         }
        //         else return 0;
        //     }
        //     else if(s[i-1]=='1'||(s[i-1]=='2' && s[i]>='1' && s[i]<='6')){
        //         curr=curr+pre;
        //         }
        //     pre=temp;
        // }
        // return curr;

        //三叶
        int n = s.size();
        s = " " + s;
        vector<int> f(n + 1,0);
        f[0] = 1;        
        for(int i = 1; i < n + 1; i++) {
            int a = s[i] - '0', b = (s[i - 1] - '0') * 10 + s[i] - '0';
            if(1 <= a && a <= 9) f[i] = f[i - 1];
            if(10 <= b && b <= 26) f[i] += f[i - 2];
        }
        return f[n];

    }
};
// @lc code=end

