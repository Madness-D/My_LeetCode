/* ************************************************************************
> File Name:		474一和零.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-08 21:33:06
> Link:		https://leetcode.cn/problems/ones-and-zeroes/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //子集，0的个数<m, 1的个数<n
        //两个维度的背包，0的个数、1的个数
        //dp数组： dp[i][j]表示最多有i个0和j个1的子集长度
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(string s:strs){
            //统计0和1的个数
            int zerocnt=0,onecnt=0;
            for(char c:s){
                if(c=='0') zerocnt++;
                else onecnt++;
            }

            //遍历两个维度
            for(int i=m;i>=zerocnt;i--){
                for(int j=n;j>=onecnt;j--){
                    //即，更新可以放下字符串s的dp[i][j]的情况
                    dp[i][j]=max(dp[i][j], dp[i-zerocnt][j-onecnt]+1);
                }
            }
        }
        return dp[m][n];
    }
};