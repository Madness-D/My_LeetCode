/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //哈希表
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second==1) return it->first;
        }
        
    return 0;

    }
};
// @lc code=end

