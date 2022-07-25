/* ************************************************************************
> File Name:		718最长重复子数组.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-25 14:31:59
> Link:		https://leetcode.cn/problems/maximum-length-of-repeated-subarray/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //dp[i][j]表示以nums1[i-1]和nums[j-1]结尾的最长重复子数组的长度（该数组必须包括nums[i]和nums[j]）
        int m=nums1.size(),n=nums2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(nums1[i]==nums2[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                    ans=max(ans,dp[i+1][j+1]);
                }
            }
        }
        return ans;

    }
};