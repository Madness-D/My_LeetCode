/* ************************************************************************
> File Name:		53最大子数组和.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-22 16:11:21
> Link:		https://leetcode.cn/problems/maximum-subarray/
> Description:		给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int ans=INT_MIN;
        /*
        for(int n:nums){
            if(sum>0) sum+=n;
            else sum=n;
        ans=max(ans,sum);
        }
        */
       for(int n:nums){
            sum+=n;
            if(sum>ans) ans=sum;
            //sum=sum<0?0:sum;
            if(sum<0) sum=0;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums{5,4,-1,7,8};
    cout<<sol.maxSubArray(nums)<<endl;
    return 0;

}