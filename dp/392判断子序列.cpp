/* ************************************************************************
> File Name:		392判断子序列.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-25 15:33:58
> Link:		https://leetcode.cn/problems/is-subsequence/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // //双指针
        // int p1=0,p2=0;
        // if(s.size()==0) return true;
        // while(p1<s.size() && p2<t.size()){
        //     if(s[p1]==t[p2]){
        //         p1++;
        //     }
        //     //下面不是s.size()-1 否则过不去"b" "c"这个用例
        //     //if(p1==s.size()) return true;
        //     p2++;
        // }
        // return p1==s.size();

        //如果二者的最长公共子序列长度==s的长度，则说明s是t的子序列
        int n1=s.size(),n2=t.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(s[i]==t[j]) dp[i+1][j+1]=1+dp[i][j];
                //注意这里的递推公式
                else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }

        return dp[n1][n2]==n1;
    }
};