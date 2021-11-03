/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st;
        for(int num:nums){
            if(num>0) st.insert(num);
        }
        for(int i=1;;i++){
            if(!st.count(i)){
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

