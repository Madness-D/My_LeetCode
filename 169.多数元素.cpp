/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
    //     //哈希表
    //     unordered_map<int,int> mp;
    //     for(int i=0;i<nums.size();i++){
    //         mp[nums[i]]++;
    //     }
    //     int n=nums.size()/2;
    //     for(auto it=mp.begin();it!=mp.end();it++){
    //         if(it->second>n) return it->first;
    //     }
        
    // return 0;

    //排序后目标数字在中间
    // sort(nums.begin(),nums.end());
    // return nums[nums.size()/2];

        int candidate = -1;
        int count = 0;
        for (int num : nums) {
            if (num == candidate)
                ++count;
            else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }
        return candidate;

    }
};
// @lc code=end

