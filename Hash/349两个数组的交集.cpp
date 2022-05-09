/* ************************************************************************
> File Name:		349两个数组的交集.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-09 23:31:30
> Link:		https://leetcode.cn/problems/intersection-of-two-arrays/
> Description:		给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是唯一的。我们可以 不考虑输出结果的顺序.
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        for(int n:nums1){
            st.insert(n);
        }
        vector<int> ans;
        for(int n:nums2){
            if(st.count(n)){
                ans.emplace_back(n);
                st.erase(n);
            }
        }
        return ans;
    }
};