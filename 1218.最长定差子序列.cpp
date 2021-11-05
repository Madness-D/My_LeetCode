/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 *
 * [1218] 最长定差子序列
 */

// @lc code=start
class Solution {
public:
    // //复杂度是n^2的方法,日常超时
    int longestSubsequence(vector<int>& arr, int difference) {
    //     int n=arr.size();
    //     int res=0;
    //     for(int i=0;i<n;i++){
    //         int temp1=1,temp2=arr[i];
    //         for(int j=i+1;j<n;j++){
    //             if(arr[j]==temp2+difference){
    //                 temp2=arr[j];
    //                 temp1++;
    //             }
    //         }
    //         res=temp1>res?temp1:res;
    //     }
    //     return res;
    
    //dp,怎么搞捏
    //dp[v]表示以v 为结尾的最长的等差子序列的长度
    //dp[v−d] 就是我们要找的左侧元素对应的最长的等差子序列的长度
    //dp[v]=dp[v−d]+1
        int ans = 0;
        unordered_map<int, int> dp;
        for (int v: arr) {
            dp[v] = dp[v - difference] + 1;
            ans = max(ans, dp[v]);
        }
        return ans;

    
    }
};
// @lc code=end

