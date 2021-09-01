/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {

    //     //哈希表
    //     unordered_map<int,int> mp;
    //     for(int i=0;i<nums.size();i++){
    //         mp[nums[i]]++;
    //     }

    //     for(auto it=mp.begin();it!=mp.end();it++){
    //         if(it->second==1) return it->first;
    //     }
        
    // return 0;


    // 异或的性质
    // 1、一个数和自身异或为0
    // 2、一个数和0异或，为自己本身
    // 3、异或满足结合律和交换律
    int res=0;
    for(int i=0;i<nums.size();i++){
        res^=nums[i];
    }
    return res;

    }
};
// @lc code=end

