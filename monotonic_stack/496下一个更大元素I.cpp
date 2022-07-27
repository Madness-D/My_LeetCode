/* ************************************************************************
> File Name:		496下一个更大元素I.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-27 15:34:10
> Link:		https://leetcode.cn/problems/next-greater-element-i/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //需要记录一下nums1与nums2 的元素对应关系
        //数组中的元素不重复
         unordered_map<int,int> mp; //记录nums1里的元素与下标的对应关系
         for(int i=0;i<nums1.size();i++){
             mp[nums1[i]] =i;
        }
        
        stack<int> st;
        vector<int> ans(nums1.size(),-1);

        //接下来在nums2这个数组里,查找每个元素的下一个更大的元素，并根据mp来判断该元素是否在nums1里
        for(int i=0;i<nums2.size();i++){
            while(!st.empty() && nums2[i]>nums2[st.top()]){
                //下面的嵌套的可能比较乱，mp里存的是元素值--下标
                if(mp.count(nums2[st.top()])){ //栈顶元素存在
                    //根据元素nums2[st.top()] 通过map找到在nums1里的下标
                    ans[mp[nums2[st.top()]]]=nums2[i];
                }
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};