/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums) {
        //其实只要知道最小值就行了，不需要排序
        int min=INT_MAX;
        for(int num:nums){
            if(num<min)
                min=num;
        }
        //sort(nums.begin(),nums.end());
        int res=0;
        for(int num:nums){
            res+=num-min;
        }
        return res;
    }
};
// @lc code=end

