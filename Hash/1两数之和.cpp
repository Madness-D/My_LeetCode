/* ************************************************************************
> File Name:		1两数之和.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-09 23:34:48
> Link:		https://leetcode.cn/problems/two-sum/
> Description:		懒得描述了。思路也不描述了
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++){
        if(mp.count(target-nums[i])) return {i,mp[target-nums[i]]};
        else{
            mp[nums[i]]=i;
        }
    }
    return {};
    }
};