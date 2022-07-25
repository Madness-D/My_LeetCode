/* ************************************************************************
> File Name:		213打家劫舍II.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-21 16:45:08
> Link:		https://leetcode.cn/problems/house-robber-ii/
> Description:		相邻不能同时偷 且 首尾不能同时偷
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int rob(vector<int>& nums, int l, int r){
        if(l==r) return nums[l];
        vector<int> dp(r-l+1,0);
        dp[0]=nums[l];
        dp[1]=max(nums[l],nums[l+1]);
        for(int i=2;i<r-l+1;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[l+i]);
        }
        return dp[r-l];
    }
public:
    int rob(vector<int>& nums) {
        //环形，一个简单的思路，分别[0,len-2] [1,len-1]进行求解，然后求最大值
        int len=nums.size();
        if(len==1) return nums[0];
        int ans1=rob(nums, 0, len-2);
        int ans2=rob(nums,1,len-1);
        return max(ans1,ans2);
    }
};