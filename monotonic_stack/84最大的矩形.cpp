/* ************************************************************************
> File Name:		84最大的矩形.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-27 20:21:09
> Link:		https://leetcode.cn/problems/largest-rectangle-in-histogram/
> Description:	求在该柱状图中，能够勾勒出来的矩形的最大面积。	
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // int  len=heights.size();
        // //优化，关于求左右两侧的第一个小于该柱子的下标
        // vector<int> ll(len,-1);
        // for(int i=1;i<len;i++){
        //     int t=i-1;
        //     while(t>=0 && heights[t]>=heights[i]) t=ll[t];//不是一个个递减，而是动态规划
        //     ll[i]=t;
        // }
        // vector<int> rl(len,len);
        // for(int i=len-2;i>=0;i--){
        //     int t=i+1;
        //     while(t<len && heights[t]>=heights[i]) t=rl[t];
        //     rl[i]=t;
        // }
        // int ans=0;
        // for(int i=0;i<len;i++){
        //     ans=max(ans,heights[i]*(rl[i]-ll[i]-1));
        // }
        // return ans;


         //单调栈，但该题是求下一个/上一个更小的值，因此是栈顶元素最大
           
        int ans=0;
        heights.insert(heights.begin(), 0);
        heights.emplace_back(0); 
        int len=heights.size();
        stack<int> st;
        st.push(0);
        for(int i=1;i<len;i++){
            while(heights[i]<heights[st.top()]){
                int top=st.top();
                st.pop();
                //if(st.empty()) break;
                ans=max(ans,heights[top]*(i-st.top()-1));
            }
            st.push(i);
        }
        return ans;
    }
};