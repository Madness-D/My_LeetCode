/* ************************************************************************
> File Name:		53最大子数组.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-03 20:11:02
> Link:		https://leetcode.cn/problems/maximum-subarray/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//之前贪心做过，这是动态规划
     int maxSubArray(vector<int>& nums) {
        //动态规划： dp[i]表示以nums[i]结尾
        //dp[i]=max(nums[i],dp[i-1]+nums[i]);
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=max(nums[i],nums[i]+dp[i-1]);
        }
        //return dp[nums.size()-1];
        int ans=INT_MIN;
        for(int i:dp)
            ans=max(ans,i);

        return ans;

    }
};