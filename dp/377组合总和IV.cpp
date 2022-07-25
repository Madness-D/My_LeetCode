/* ************************************************************************
> File Name:		377组合总和IV.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-20 21:19:49
> Link:		https://leetcode.cn/problems/combination-sum-iv/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //动态规划，关键是如果定义数组？
        //如果按照nums来定义数组，
        //dp[i]表示组成i的组合数？ dp[i]=sum(dp[i-nums[j]])

        sort(nums.begin(),nums.end());
        vector<int> dp(target+1,0);
        dp[0]=1;
        // for(int i:nums){
        //     if(i<=target) dp[i]=1;
        // }

        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                //题目只说了最后答案不超过，但该过程中的dp值可能超过
                if(i-nums[j]>=0 && dp[i-nums[j]]<=INT_MAX-dp[i]) dp[i]+=dp[i-nums[j]];
            }
        }
        return dp[target];

    } 
};