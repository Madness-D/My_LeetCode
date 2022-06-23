/* ************************************************************************
> File Name:		376摆动序列.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-22 15:10:45
> Link:		https://leetcode.cn/problems/wiggle-subsequence/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
    
        /*
        //dp
        //使用数组，优化之后使用两个变量也可以。
        int n=nums.size();
        if(n==0) return 0;
        //去重,去掉连续重复的元素
        vector<int> newnum;
        newnum.emplace_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1])
                newnum.emplace_back(nums[i]);
        }
        n=newnum.size();
        if(n<2) return n;
        vector<int> dp(n,0);
        int  pre=1, lat=2;
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;i++){
            //未考虑连续元素重复的情况，会出错。看评论区，先去重
            if((newnum[i]-newnum[i-1])*(newnum[i-1]-newnum[i-2])<0) {
                dp[i]=1+dp[i-1];
                int t=lat;
                lat=1+lat;
                pre=t;
            }
            else {
               pre=lat;
            }
        }
        return lat;
        */

       /*
        //贪心。计算峰值数量，然后+2
        //但需要一个数组来存放去重后 的数组
        int n=nums.size();
        if(n<2) return n;
        int ans=0;
        //去重,去掉连续重复的元素
        vector<int> newnum;
        newnum.emplace_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1])
                newnum.emplace_back(nums[i]);
        }
        n=newnum.size();
        if(n<2) return n;
        for(int i=1;i<n-1;i++){ 
            if((newnum[i]-newnum[i-1])*(newnum[i]-newnum[i+1])>0) ans++;
        }
        return ans+2;
        */

        //贪心，记录峰谷数量
        //如果前后的差值不一样就是峰或者谷
        int n=nums.size();
        if(n<2) return n;
        int curdiff=0;
        int prediff=0;
        int ans=0;
        for(int i=0;i<n-1;i++){
            curdiff=nums[i+1]-nums[i];
            //通过curdiff!=0过滤掉连续重复的元素
            if(prediff*curdiff<=0 && curdiff) {
                ans++;
                //只有峰值处才更新
                prediff=curdiff;
            }
        }
        return ans+1;
    }
};