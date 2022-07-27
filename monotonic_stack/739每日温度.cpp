/* ************************************************************************
> File Name:		739每日温度.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-27 10:53:47
> Link:		https://leetcode.cn/problems/daily-temperatures/
> Description:		返回下一个更高温度出现在几天后
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //单调栈，在栈中存放下标。  
        //递增栈，栈顶元素是最小的

        int len=temperatures.size();
        stack<int> st;//存放下标
        vector<int> ans(len,0);
        for(int i=0;i<len;i++){
            if(!st.empty() && temperatures[i]<=temperatures[st.top()]){
                st.push(i);
            }else{
                while(!st.empty() && temperatures[i]> temperatures[st.top()]){ //while循环
                    ans[st.top()]=i-st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return ans;
    }
};