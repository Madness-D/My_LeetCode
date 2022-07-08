/* ************************************************************************
> File Name:		343整数拆分.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-07 21:26:32
> Link:		https://leetcode.cn/problems/integer-break/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     int integerBreak(int n) {
        //动态规划，对于j， 可以拆分，也可以不拆分 dp[i]=max((i-j)dp[j]，(i-j)*j )
        vector<int> dp(n+1,0);
        dp[0]=0,dp[1]=0;
        for(int i=2;i<=n;i++){
            int t=INT_MIN;
            for(int j=1;j<i;j++){
                t=max(max(t,(i-j)*j),(i-j)*dp[j]);
            }
            dp[i]=t;
        }
        return dp[n];

        //  //贪心，
        // if(n<4) return n-1;
        // int ans=1;
        // while(n>4){
        //     n-=3;
        //     ans*=3;
        // }
        // return ans*n;


    }
};