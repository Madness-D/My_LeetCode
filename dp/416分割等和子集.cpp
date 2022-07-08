/* ************************************************************************
> File Name:		416分割等和子集.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-03 15:45:51
> Link:		https://leetcode.cn/problems/partition-equal-subset-sum/
> Description:		给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;
//转换成01背包的问题

class Solution {
public:
      bool canPartition(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return false;

        int sum=accumulate(nums.cbegin(), nums.cend(), 0);
        if(sum%2) return false;
        int target=sum/2;

        //01背包问题，一个数组，可以选，也可以不选，要求刚好凑够sum/2
        //回顾，背包问题里，dp[i]表示容量为i时的最大价值
        //dp[i]表示能否刚好凑够i
        vector<bool> dp(target,false);
        dp[0]=true;
 
        for(int i=0;i<nums.size();i++){
            for(int j=target;j>=nums[i];j--){
                dp[j] = dp[j]||dp[j-nums[i]];
            }
        }

        return dp[target];


        //  //int数组，dp[i]表示容量为i时最多能装多少
        // vector<int> dp(target+1,0);
        // for(int i=0;i<n;i++){
        //     for(int j=target;j>=nums[i];j--){
        //         dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
        //     }
        // }
        // return dp[target]==target;

    }
};