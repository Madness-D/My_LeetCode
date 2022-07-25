/* ************************************************************************
> File Name:		674最长连续递增序列.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-24 22:31:07
> Link:		https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        // //贪心
        // int ans=0,t=1;
        // for(int i=1;i<nums.size();i++){
        //     if(nums[i]>nums[i-1]){
        //         t++;
        //     }else{
        //         ans=max(ans,t);
        //         t=1;
        //     }         
        // }
        // return max(ans,t);

        int len=nums.size();
        vector<int> dp(len,1);
        int ans=1;
        for(int i=1;i<len;i++){
            if(nums[i]>nums[i-1]){
                dp[i]=dp[i-1]+1;
                ans=max(ans,dp[i]);
            }
        }
        return ans;
    }
};