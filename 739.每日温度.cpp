/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        ////超时了
        // int n=temperatures.size();
        // if(n==1){return {0};}

        // vector<int> res;
        // for(int i=0;i<n;i++){
        //     int r=i;
        //     while(r<n && temperatures[r]<=temperatures[i]){
        //         r++;
        //     }
        //     if(r==n){res.push_back(0);}
        //     else{res.push_back(r-i);}
        // }
        // //res.push_back(0);
        // return res;

        //官方题解
        // int n = temperatures.size();
        // vector<int> ans(n), next(101, INT_MAX);//数组 next 记录每个温度第一次出现的下标
        // //一定是反向遍历
        // for (int i = n - 1; i >= 0; --i) {
        //     int warmerIndex = INT_MAX;
        //     for (int t = temperatures[i] + 1; t <= 100; ++t) {
        //         warmerIndex = min(warmerIndex, next[t]);
        //     }
        //     if (warmerIndex != INT_MAX) {
        //         ans[i] = warmerIndex - i;
        //     }
        //     next[temperatures[i]] = i;
        // }
        // return ans;

        //单调栈
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int previousIndex = s.top();
                ans[previousIndex] = i - previousIndex;
                s.pop();
            }
            s.push(i);
        }
        return ans;

    
    }
};
// @lc code=end

