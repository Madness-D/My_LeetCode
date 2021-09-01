/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
        int len=nums.size();
        vector<int> res(len);
        for(int i=0;i<len;i++){
            res[(i+k)%len]=nums[i];
        }
        //nums=res;
        nums.assign(res.begin(),res.end());
        */

       //三次翻转
       k%=nums.size();
       reverse(nums.begin(),nums.end());
       reverse(nums.begin(),nums.begin()+k);
       reverse(nums.begin()+k,nums.end());
    }
};
// @lc code=end

