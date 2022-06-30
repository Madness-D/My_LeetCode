/* ************************************************************************
> File Name:		746最小花费爬楼梯.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-30 20:38:16
> Link:		https://leetcode.cn/problems/min-cost-climbing-stairs/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //从下标1或者0的位置开始
        //dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        //要求到达楼顶，且楼顶的cost=0 
        cost.emplace_back(0);
        int n=cost.size();
        vector<int> dp(n+1,0);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        }
        return dp[n-1];
    }
};