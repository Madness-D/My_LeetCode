/* ************************************************************************
> File Name:		518零钱兑换II.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-20 15:34:47
> Link:		https://leetcode.cn/problems/coin-change-2/
> Description:		完全背包问题
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //区别，一个金币可以重复用，即完全背包
        //和01背包的区别，遍历的顺序
        int len=coins.size();
        
        //dp[i]表示总和为i的组合数
        vector<int> dp(amount+1,0);
        //边界条件
        dp[0]=1;
        //注意遍历先后顺序，
        for(int i=0;i<len;i++){ //遍历物品
            for(int j=coins[i];j<=amount;j++){ //遍历背包容量， 注意这里的是正向遍历
                dp[j]+=dp[j-coins[i]]; //问有多少种组合时，
            }
        }
        return dp[amount];

    }
};