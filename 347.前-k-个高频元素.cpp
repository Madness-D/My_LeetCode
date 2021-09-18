/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //返回频率前k高的元素
        //堆，优先队列
        vector<int> ret;
        unordered_map<int, int> mp;//哈希表
        priority_queue<pair<int, int>> pq;
        for (auto i : nums) mp[i]++;//遍历存储哈希表
        for (auto p : mp) {//将哈希表中的key和value组成pair存到队列中
            //
            pq.push(pair<int, int>(-p.second, p.first));
            if (pq.size() > k) pq.pop();
        }
        while (k--) {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};
// @lc code=end

