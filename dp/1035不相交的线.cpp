/* ************************************************************************
> File Name:		1035不相交的线.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-26 09:44:17
> Link:		https://leetcode.cn/problems/uncrossed-lines/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        //最长公共子序列问题？
        ////dp[i][j]表示，到i-1和到j-1的两个字符串的LCS长度（不一定以i和j结尾）
        //如果是到i和j，对于0的处理比较繁琐
        int len1=nums1.size(),len2=nums2.size();

        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));

        for(int i=0;i<len1;i++){
            for(int j=0;j<len2;j++){
                if(nums1[i]==nums2[j]) dp[i+1][j+1]=1+dp[i][j];
                //注意这里的递推公式
                else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
        return dp[len1][len2];
    }
};