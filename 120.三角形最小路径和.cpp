/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
//艹 超时了
class Solution {
public:
    // int dp(vector<vector<int>>& t,int i,int j,int n){
    //     if(i==n-1){ return t[n-1][j];}
    //     else return t[i][j]+min(dp(t,i+1,j,n),dp(t,i+1,j+1,n));

    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n=triangle.size();
    //     if(n==1) return triangle[0][0];
    //     else return dp(triangle,0,0,n);
    // }


    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){dp[n-1][j]=triangle[n-1][j];}
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

