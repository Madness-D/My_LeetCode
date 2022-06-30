/* ************************************************************************
> File Name:		70爬楼梯.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-30 20:20:21
> Link:		https://leetcode.cn/problems/climbing-stairs/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     int climbStairs(int n) {
        //dp[i]=dp[i-1]+dp[i-2];
        //dp[0]=0;  dp[0]=1;
        //dp[1]=1;
        //dp[2]=2
        if(n<2) return 1;
        int p=1,q=1;
        int t=0;
        for(int i=2;i<=n;i++){
            t=p;p=q;
            q=t+p;
        }
        return q;

    }
};