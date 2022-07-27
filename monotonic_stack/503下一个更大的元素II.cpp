/* ************************************************************************
> File Name:		503下一个更大的元素II.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-27 15:05:07
> Link:		https://leetcode.cn/problems/next-greater-element-ii/
> Description:		循环数组，求下一个更大的元素，不存在为-1
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len=nums.size();
        stack<int> st;//递增单调栈，栈顶元素是最小的 存下标
        vector<int> ans(len,-1);
        //环形数组，因此需要遍历两遍
        for(int i=0;i<2*len;i++){
            while(!st.empty() &&  nums[i%len]> nums[st.top()] ){
                ans[st.top()]=nums[i%len];
                st.pop();
            }
            st.push(i%len);
        }
        return ans;
    }
};