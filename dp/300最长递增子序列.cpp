/* ************************************************************************
> File Name:		300最长递增子序列.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-03 20:20:13
> Link:		https://leetcode.cn/problems/longest-increasing-subsequence/
> Description:		给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //动态规划 ，dp[i]表示以nums[i]结尾的递增序列
        int n=nums.size();
        vector<int> dp(n,1);
         int ans=INT_MIN;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            ans=max(ans,dp[i]);
        }
       

        return ans;
    }
};