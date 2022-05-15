/* ************************************************************************
> File Name:		15三数之和.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-11 20:44:11
> Link:		https://leetcode.cn/problems/3sum/
> Description:		给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。

> 思路： 重点和难点在于如何去掉重复的三元组，这道题虽然归类于hash，但应该用双指针来做

*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
        //先sort 再循环内嵌一个双指针遍历
        int len=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(int i=0;i<len;i++){//外层循环
            if(i>0 && nums[i]==nums[i-1]) continue; //去重
            if(nums[i]>0 ) return ans; //若a>0则不可能总和==0

            //双指针遍历nums[i]后面的元素
            int l=i+1,r=len-1;
            while(l<r){
                int t=nums[i]+nums[l]+nums[r];
                if(t==0){ //找到一组
                    vector<int> vtt={nums[i],nums[l],nums[r]};
                    ans.emplace_back(vtt);
                    //后面的四个while循环都是为了去重，且如果没有l<r 这个条件，对于[0,0,0]会出错
                    while(l<r && nums[l]==nums[l+1]) l++; 
                    while(l<r && nums[r]==nums[r-1]) r--;
                    //执行上述两个循环后，l和r分别指向重复元素的边界（即，仍指向重复元素），因此需要分别再++、--
                    l++;r--;
                 }else if(t<0){
                     l++; //先移动指针再去重
                     while(l<r && nums[l]==nums[l-1]) l++; //注意循环的条件，这时l指向的不是重复的元素
                 }else{
                     r--;
                     while(l<r && nums[r]==nums[r+1]) r--; //同上
                 }
            }
        }
        return ans;
    }
};