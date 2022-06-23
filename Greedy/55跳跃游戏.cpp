/* ************************************************************************
> File Name:		55跳跃游戏.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-22 17:35:18
> Link:		https://leetcode.cn/problems/jump-game/
> Description:		给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        /*
        //遍历，遇到0的，看前面有没有能够跳过去的，没有就false
        int n=nums.size();
        if(n==1) return true;
        //
        //注意，到倒数第二个元素，因为如2，0，0
        for(int i=0;i<n-1;i++){
            if(nums[i]>0) continue;
            else{
                bool flag=false;
                for(int j=i-1;j>=0;j--){
                    if(nums[j]+j>i){
                        flag=true;
                        break;
                    }
                }
                if(!flag) return false;
            }
        }
        return true;
        */
        int n=nums.size();
        int maxrange=0;
        for(int i=0;i<=maxrange;i++){
            maxrange=max(maxrange,i+nums[i]);
            if(maxrange>=n-1) return true;
        }
        return false;
    }
};