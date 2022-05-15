/* ************************************************************************
> File Name:		18四数之和.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-15 17:02:21
> Link:		https://leetcode.cn/problems/4sum/
> Description:		给你一个由n个整数组成的数组nums，和一个目标值target。请你找出并返回满足下述全部条件且不重复的四元组[nums[a],nums[b],nums[c],nums[d]]; 
> 思路： 和三数之和一样，双指针，但注意溢出问题，因此将和转换成差
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
 vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //使用双指针将复杂度从n^4降到n^3
        int len=nums.size();
        sort(nums.begin(),nums.end());
        if(len<4)  return{};
        vector<vector<int>> ans;
        for(int a=0;a<len-3;a++){
            if(a>0 && nums[a]==nums[a-1]) continue;
            for(int b=a+1;b<len-2;b++){
                if(b>a+1 && nums[b]==nums[b-1]) continue;

                int l=b+1,r=len-1;
                while(l<r){
                long t1=nums[l]+nums[r];
                long t2=nums[a]+nums[b];
                if(t1==target-t2){
                    vector<int> vtt={nums[a],nums[b],nums[l],nums[r]};
                    ans.emplace_back(vtt);
                    while(l<r && nums[l]==nums[l+1]) l++;
                    while(l<r && nums[r]==nums[r-1]) r--;
                    l++;r--;
                }else if(t1<target-t2){
                    l++;
                    while(l<r && nums[l]==nums[l-1]) l++;
                }else{
                    r--;
                    while(l<r && nums[r]==nums[r+1]) r--;
                }
                }
            }
        }
        return ans;
    }
    
};