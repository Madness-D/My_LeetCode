/* ************************************************************************
> File Name:		198打家劫舍.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-21 16:31:25
> Link:		https://leetcode.cn/problems/house-robber/
> Description:		相邻不能同时偷
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len=nums.size();
        if(len<2) return nums[0];
        vector<int> dp(len,0);
        dp[0]=nums[0];dp[1]=max(nums[1],nums[0]);
        for(int i=2;i<len;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[len-1];

    }
};