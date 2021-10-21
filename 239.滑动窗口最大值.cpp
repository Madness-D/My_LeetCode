/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //vector<int> res;

        ////没有考虑最大值是滑动窗口的最左侧的情况
        // int max=INT_MIN;
        // for(int i=0;i<k;i++){
        //     if(nums[i]>max)
        //         max=nums[i];
        // }
        // res.push_back(max);
        // for(int i=k;i<nums.size();i++)
        


        // //来个暴力法？估计是n^2复杂度了,通过49/61，gg
        // for(int i=0;i<nums.size()-k+1;i++){
        //     int max=INT_MIN;
        //     for(int j=0;j<k;j++){
        //         if(nums[j+i]>max)
        //             max=nums[i+j];
        //     }
        //     res.push_back(max);
        // }
        // return res;

        //优先队列
        int n = nums.size();
        //第一个int存数值，第二个int存下标
        priority_queue<pair<int, int>> q;
        //将前k个元素存入队列
        for (int i = 0; i < k; ++i) {
            q.emplace(nums[i], i);
        }
        //vector<int> ans = {q.top().first};
        vector<int> ans;
        ans.push_back(q.top().first);
        for (int i = k; i < n; ++i) {
            q.emplace(nums[i], i);
            //只有在最大元素的下标不在窗口内的时候才需要pop，否则其实没有影响
            while (q.top().second <= i - k) {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;

    }
};
// @lc code=end

