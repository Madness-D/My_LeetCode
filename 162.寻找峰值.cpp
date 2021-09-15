/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // //遍历
        // if(nums.size()==2){
        //     return nums[0]>nums[1]?0:1;
        // }
        // nums.push_back(-INT_MAX);//防止出现最后一个为答案的情况
        // for(int i=1;i<nums.size()-1;i++){
        //     if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]){
        //         return i;
        //     }
        // }
        // return 0;

        //返回最大值
        //max_element 返回的是地址
        return max_element(nums.begin(), nums.end()) - nums.begin();
    }
};
// @lc code=end

