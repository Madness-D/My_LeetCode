/* ************************************************************************
> File Name:		45跳跃游戏II.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-22 21:05:38
> Link:		https://leetcode.cn/problems/jump-game-ii/
> Description:		使用最少的跳跃次数到达数组的最后一个位置。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        //最小跳数
        //如果单纯地，每次跳最远的距离，并不是答案，如示例2
        //贪心或者动态规划 
        //贪心？
        if(nums.size()==1) return 0;
        int ans=1;
        int currange=nums[0];
        int nextrange=0;
        for(int i=0;i<nums.size()-1;i++){
            nextrange=max(nums[i]+i,nextrange);
            if(i==currange){
                ans++;
                currange=nextrange;
            }
        }
        return ans;
    }
};