/* ************************************************************************
> File Name:		42接雨水.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-27 17:23:13
> Link:		https://leetcode.cn/problems/trapping-rain-water/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        //按行计算，即如示例1的第二个接雨水区域，是1+3

        //单调栈，存储下标，从栈底到栈顶递减
        //当栈的元素至少为2个时， 记栈顶对应的高度为toph， 第二个元素对应的高度为 sech， 有sech>=toph
        //假设当前的高度为ih， 如果ih>toph  ans+=(i-sec-1)*(min(h[sec],h[i])-h[top])
        
        int ans = 0;
        stack<int> stk;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top(); //
                stk.pop();
                if (stk.empty()) { //栈内只有一个元素
                    break;
                }
                int left = stk.top(); 
                int currWidth = i - left - 1;
                int currHeight = min(height[left], height[i]) - height[top];
                ans += currWidth * currHeight;
            }
            stk.push(i);
        }
        return ans;


    } 
};