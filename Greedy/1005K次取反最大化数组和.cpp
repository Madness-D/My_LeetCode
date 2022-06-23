/* ************************************************************************
> File Name:		1005K次取反最大化数组和.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-23 20:00:53
> Link:		https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),[](int a,int b){return abs(a)>abs(b);});
        int ans=0;
        for(int  &i:nums){
            if(i<0 && k){
                i*=-1;
                k--;
            }
            ans+=i;
        }
        ans-=nums[nums.size()-1];
        if(k%2) nums[nums.size()-1]*=-1;
        ans+=nums[nums.size()-1];
        return ans;
    }
};