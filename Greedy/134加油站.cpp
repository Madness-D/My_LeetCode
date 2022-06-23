/* ************************************************************************
> File Name:		134加油站.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-23 21:33:34
> Link:		https://leetcode.cn/problems/gas-station/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //如果gas<cost直接就不可能是答案
        // //暴力，因为是环形的，用while循环
        // //超时
        // for(int i=0;i<gas.size();i++){
        //    // if(gas[i]<cost[i]) continue;
        //     int res=gas[i]-cost[i];
        //     int idx=(i+1)%gas.size();
        //     while(res>0 && idx!=i){
        //         res+=gas[idx]-cost[idx];
        //         idx=(idx+1)%gas.size();
        //     }
        //     if(res>=0 && idx==i) return i;
        // }
        // return -1;

        //如果x到不了y+1（但能到y），那么从x到y的任一点出发都不可能到达y+1
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {   // 当前累加rest[i]和 curSum一旦小于0
                start = i + 1;  // 起始位置更新为i+1
                curSum = 0;     // curSum从0开始
            }
        }
        if (totalSum < 0) return -1; // 说明怎么走都不可能跑一圈了
        return start; 

    }
};