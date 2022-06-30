/* ************************************************************************
> File Name:		62不同路径.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-30 20:41:26
> Link:		https://leetcode.cn/problems/unique-paths/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        //dp[i][j]=dp[i-1][j]+dp[i][j-1]
        //边界，dp[0][0]=0; dp[0][i]=1; dp[i][0]=1
        vector<vector<int>> dp(m,vector<int>(n,1));
        //dp[0][0]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};