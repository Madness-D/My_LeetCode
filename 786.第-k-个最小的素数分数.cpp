/*
 * @lc app=leetcode.cn id=786 lang=cpp
 *
 * [786] 第 K 个最小的素数分数
 */

// @lc code=start
class Solution {
public:
    //暴力法的比较函数
    static bool cmp(pair<int,int> x,pair<int,int> y){
        return x.first * y.second < x.second * y.first;
    } 
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        // //暴力法
        // vector<pair<int,int>> vt;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         vt.push_back({arr[i],arr[j]});
        //     }
        // }
        // sort(vt.begin(),vt.end(),cmp);
        // return {vt[k-1].first,vt[k-1].second};

        auto cmp = [&](const pair<int, int>& x, const pair<int, int>& y) {
            return arr[x.first] * arr[y.second] > arr[x.second] * arr[y.first];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (int j = 1; j < n; ++j) {
            q.emplace(0, j);
        }
        for (int _ = 1; _ < k; ++_) {
            auto [i, j] = q.top();
            q.pop();
            if (i + 1 < j) {
                q.emplace(i + 1, j);
            }
        }
        return {arr[q.top().first], arr[q.top().second]};
    }
};
// @lc code=end

