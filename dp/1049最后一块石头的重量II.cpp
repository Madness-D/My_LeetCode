/* ************************************************************************
> File Name:		1049最后一块石头的重量II.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-08 20:42:15
> Link:		https://leetcode.cn/problems/last-stone-weight-ii/
> Description:		石头两两抵消，求最后最小的可能重量
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //两块石头，碰撞之后的重量为二者之差
        //问题转换： 将石头分为两堆，重量尽量接近sum/2
        //求容量为sum/2 的背包的最大重量，s/2-dp-dp

        int n=stones.size();
        int sum=accumulate(stones.cbegin(), stones.cend(), 0);
        int target=sum/2;

        vector<int> dp(target+1,0);

        for(int i=0;i<n;i++){
            for(int j=target;j>=stones[i];j--){
                dp[j]=max(dp[j-stones[i]]+stones[i],dp[j]);
            }
        }
        return sum-2*dp[target];
        
    }
};