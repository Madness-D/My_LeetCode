/* ************************************************************************
> File Name:		454四数相加II.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-12 00:46:28
> Link:		https://leetcode.cn/problems/4sum-ii/
> Description:		给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n, 请你计算有多少个元组满足相加为0
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        //遍历 A 和 B 所有元素和的组合情况，并记录在 ab_map 中，ab_map 的 key 为两数和，value 为该两数和出现的次数
        //遍历 C 和 D 所有元素和的组合情况，取和的负值判断其是否在 ab_map 中，若存在则取出 ab_map 对应的 value 值，count = count + value
        unordered_map<int, int> mp;
        int ans=0;
        for(int &a:nums1){
            for(int &b:nums2){
                mp[a+b]++;
            }
        }
        for(int &c:nums3){
            for(int &d:nums4){
                if(mp.count(-c-d)) ans+=mp[-c-d];
            }
        }
        return ans;
    }
};