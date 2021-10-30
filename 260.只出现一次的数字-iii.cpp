/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //
        unordered_set<int> us;
        for(int num:nums){
            if(us.count(num)){
                us.erase(num);
            }else{
                us.insert(num);
            }
        }
        vector<int> res;
        for(int num:us){
            res.push_back(num);
        }
        return res;

    }
};
// @lc code=end

