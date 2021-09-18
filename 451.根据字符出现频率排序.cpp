/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    // string frequencySort(string s) {
    //     //哈希表
    //     unordered_map<char, int> mp;
    //     for (auto i : s) mp[i]++;

    //     priority_queue<pair<char, int>> pq;
    //     for (auto p : mp) {//将哈希表中的key和value组成pair存到队列中
    //         //
    //         pq.push(pair<char, int>(p.second, p.first));
    //     }

    //     string res;
    //     //
    //     while(!pq.empty()){
    //         int k=pq.top().second;
    //         while(k--){
    //             res+=pq.top().first;
    //         }
    //         pq.pop();
    //     }

    //     return res;

    // }
    using PIC = pair<int, char>;
    string frequencySort(string s) {
        unordered_map<char, int> um;
        for(auto c:s)
            um[c]++;
        
        priority_queue<PIC, vector<PIC>, less<PIC>> pq;
        for(auto &[key, value] : um)
            pq.push({value, key});
        
        string ans = "";
        while(!pq.empty()) {
            auto [num, c] = pq.top();
            pq.pop();
            ans += string(num, c);
        }
        return ans;
    }


};
// @lc code=end

