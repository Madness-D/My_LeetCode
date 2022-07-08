/* ************************************************************************
> File Name:		494目标和.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-08 21:18:16
> Link:		https://leetcode.cn/problems/target-sum/
> Description:		返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //动态规划，要求装满的方法
        int n=nums.size();
        //同样的思路，一个数两种可能，＋　或者　－
        // 假设全为+的是l，全为-的是r，则有l-r=target, l+r=sum
        //l=(sum+target)/2,  
        int sum=accumulate(nums.cbegin(), nums.cend(), 0);
        if(abs(target)>sum) return 0;
        if((sum+target)%2) return 0;
        int neotarget=(sum+target)/2;
        //转换成，组成neotarget的组合有多少
        //dp[j]表示总和为j的组合数
         vector<int> dp(neotarget+1,0);
        dp[0]=1;
         for(int i=0;i<n;i++){
             for(int j=neotarget;j>=nums[i];j--){
                 dp[j]+=dp[j-nums[i]];
             }
         }
        return dp[neotarget];


        //另有回溯做法，复杂度偏高，不写了
    }
};