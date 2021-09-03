/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    //     //暴力循环
    //     //艹 超时了
    //     int len=nums.size();
    //     int res=0;
    //     for(int i=0;i<len;++i){
    //         int sum=0;
    //         for(int j=i;j<len;j++){
    //             sum+=nums[j];
    //             if(sum==k){res++;}
    //         }
    //     }
    // return res;

    //前缀和,hash table优化
    //将前缀和作为key存到hash表中，value是出现的次数
    //那么对于当前元素的前缀和pre来说，
    //之前的所有前缀和中符合pre-k的value就是符合题意的子数组个数
    //遍历，查找，相加
        unordered_map<int, int> mp;
        mp[0] = 1;
        int res = 0, pre = 0;
        for (auto& x:nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) {
                res += mp[pre - k];
            }
            mp[pre]++;
        }
        return res;

    }
};
// @lc code=end

