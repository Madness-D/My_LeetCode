/* ************************************************************************
> File Name:		63不同路径II.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-30 20:48:35
> Link:		https://leetcode.cn/problems/unique-paths-ii/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        //dp[i][j]=dp[i-1][j]+dp[i][j-1]
        //边界，dp[0][0]=0; dp[0][i]=1; dp[i][0]=1
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1] || obstacleGrid[0][0]) return 0;

        vector<vector<int>> dp(m,vector<int>(n,0));
         for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;


        //dp[0][0]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]) dp[i][j]=0;
                if(!obstacleGrid[i][j]){dp[i][j]=dp[i-1][j]+dp[i][j-1];}
            }
        }
        return dp[m-1][n-1];
    }
};