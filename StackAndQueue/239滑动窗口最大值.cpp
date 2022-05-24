/* ************************************************************************
> File Name:		239滑动窗口最大值.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-24 15:44:32
> Link:		https://leetcode.cn/problems/sliding-window-maximum/
> Description:		给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。返回 滑动窗口中的最大值 。

*************************************************************************/
#include<bits/stdc++.h>
using namespace std;
 //单调队列，在队列中维护“可能成为最大值”的值，保持队列单调递减
    //声明时可维护的
    //如何维护其单调性质？
        // pop(value)：如果窗口移除的元素value等于单调队列的出口元素，那么队列弹出元素，否则不用任何操作
        //push(value)：如果push的元素value大于入口元素的数值，那么就将队列入口的元素弹出，直到push元素的数值小于等于队列入口元素的数值为止


class Solution {
    class MyQueue { //单调队列（从大到小）
    public:
        deque<int> que; // 使用deque来实现单调队列
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        // 同时pop之前判断队列当前是否为空。
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
        }
        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
        // 这样就保持了队列里的数值是单调从大到小的了。
        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);

        }
        // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
        int front() {
            return que.front();
        }
    };
public:
     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // //优先队列，存储元素和下标信息，需要根据下标判断是否在当前窗口内
        // //大根堆
        // vector<int> ans;
        // priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;

        // for(int i=0;i<k;i++){
        //     pq.emplace(nums[i],i);
        // }
        // ans.emplace_back(pq.top().first);
        // for(int i=k;i<nums.size();i++){
        //     pq.emplace(nums[i],i);
        //     while(pq.top().second<=i-k) pq.pop();
        //     ans.emplace_back(pq.top().first);
        // }
        // return ans;   

        //单调队列
        MyQueue que;
        vector<int> result;
        for (int i = 0; i < k; i++) { // 先将前k的元素放进队列
            que.push(nums[i]);
        }
        result.push_back(que.front()); // result 记录前k的元素的最大值
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]); // 滑动窗口移除最前面元素
            que.push(nums[i]); // 滑动窗口前加入最后面的元素
            result.push_back(que.front()); // 记录对应的最大值
        }
        return result;
    }
};