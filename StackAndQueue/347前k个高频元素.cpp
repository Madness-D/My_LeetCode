/* ************************************************************************
> File Name:		347前k个高频元素.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-05-24 10:31:33
> Link:		https://leetcode.cn/problems/top-k-frequent-elements/
> Description:		给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
> 思路：       典型的top_k,用优先队列
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static  bool mySort(pair<int,int> &p1, pair<int,int> &p2){
        return p1.second>p2.second;
    }

    struct mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };


    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int n:nums){
            mp[n]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(&mySort)> pq(mySort);
       // priority_queue<pair<int,int>, vector<pair<int,int>>, mycomparison> pq;
        for(auto it:mp){
            if(pq.size()<k){
                pq.emplace(it.first,it.second);
            }else{
                if(it.second>pq.top().second){
                    pq.pop();
                    pq.emplace(it.first,it.second);
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()){ //优先队列不能遍历
            ans.emplace_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};

/*
优先队列 priority_queue
    默认是大顶堆，即top是最大的元素
    声明的参数： 存储的元素类型、 底层容器类型、比较的函数

如何声明自己的比较函数
1、直接定义一个bool函数
    a、如果是定义在同一个类内，需要加上static关键字，如果是定义在类外则不需要
    b、声明时的第三个参数是该函数的类型，建议用decltype关键字，且需要传入实际的函数名
2、定义一个结构体，重载()运算符 ，这样直接在第三个参数传入结构体的类型名即可

⭐定义的比较函数，可能和直觉相反，比如小顶堆，是定义大于号

*/