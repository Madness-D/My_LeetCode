/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 */

// @lc code=start
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
            int len=nums.size();
            // vector<int> res(len);
            // res[0]=nums[0];
            // for(int i=1;i<len;i++){
            //     res[i]=res[i-1]+nums[i];
            // }
            // return res;

            //原地修改
            for(int i=1;i<len;i++){
                nums[i]+=nums[i-1];
            }
            return nums;
            
    }
};
// @lc code=end

