/*
 * @lc app=leetcode.cn id=945 lang=cpp
 *
 * [945] 使数组唯一的最小增量
 */

// @lc code=start
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        //先来个sort
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int res =0;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                res+=nums[i-1]+1-nums[i];
                nums[i]=nums[i-1]+1;
                
            }
        }
        return res;
    }
};
// @lc code=end

