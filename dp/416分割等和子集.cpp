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
        //转换成01背包问题。
        //区别在于，背包问题允许不装满
        vector<bool> dp(target,false);
        dp[0]=true;
 
        for(int i=0;i<nums.size();i++){
            for(int j=target;j>=nums[i];j--){
                dp[j] = dp[j]||dp[j-nums[i]];
            }
        }

        return dp[target];

    }
};