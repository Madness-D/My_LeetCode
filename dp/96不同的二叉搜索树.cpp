/* ************************************************************************
> File Name:		96不同的二叉搜索树.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-03 19:41:35
> Link:		https://leetcode.cn/problems/unique-binary-search-trees/
> Description:		给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        //假设连续n个数的二叉搜索树个数为G(n)=f(1)+f(2)+...f(n)  f(i)表示以第i个数为根的子树个数
        // f(i):  i将1--n分为 1--i-1 和 i+1 --- n， 即f(i)=G(i-1)*G(n-i)
        //so, G(n)=G(0)G(n-1)+G(1)G(n-2)+.....G(n-1)G(0)
        //G(0)?   G(1)=G(0)=1
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i]+=dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};