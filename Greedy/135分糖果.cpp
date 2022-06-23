/* ************************************************************************
> File Name:		135分糖果.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-23 20:54:29
> Link:		https://leetcode.cn/problems/candy/
> Description:		每个孩子至少分配到 1 个糖果。
相邻两个孩子评分更高的孩子会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n==1) return 1;
        vector<int> can(n,1);
        //贪心，关键是，必须两次遍历，不能一次遍历同时考虑左右
         for(int i=1;i<n;i++){
             if(ratings[i]>ratings[i-1]) can[i]=can[i-1]+1;
         }
         for(int i=ratings.size()-2;i>=0;i--){
             if(ratings[i]>ratings[i+1]) can[i]=max(can[i],can[i+1]+1);
         }
         int ans=0;
         for(int nu:can){
             ans+=nu;
         }
         return ans;
    }
};