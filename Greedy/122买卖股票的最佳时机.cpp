/* ************************************************************************
> File Name:		122买卖股票的最佳时机.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-22 17:27:33
> Link:		https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
> Description:		给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
返回 你能获得的 最大 利润 

*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        //可以在同一天出售
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) ans+=nums[i]-nums[i-1];
        }
        return ans;
    }
};