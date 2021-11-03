/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // unordered_set<int> st;
        // for(int num:nums){
        //     if(num>0) st.insert(num);
        // }
        // for(int i=1;;i++){
        //     if(!st.count(i)){
        //         return i;
        //     }
        // }
        // return -1;

        //要求常数级空间，那么把原数组作为bool数组
        //n是数组的长度，把所有<0的数置为n+1
        //对于前n个数，将对应索引处的值变为负数
        int n = nums.size();
        for (int i = 0; i < n; i++) if (nums[i] <= 0) nums[i] = n + 1;
        for (int i = 0; i < n; i++) if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] *= -1;
        for (int i = 0; i < n; i++) if (nums[i] > 0) return i + 1;
        return n + 1;
    }
};
// @lc code=end

