/*
 * @lc app=leetcode.cn id=1646 lang=cpp
 *
 * [1646] 获取生成数组中的最大值
 */

// @lc code=start
class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0) return 0;
        vector<int> nums(n+1);
        
        nums[0]=0,nums[1]=1;
        int maxval=nums[1];
        for(int i=2;i<n+1;i++){
            nums[i]=nums[i/2]+(i%2)*nums[i/2+1];
            // if(i%2==0){nums[i]=nums[i/2];}else
            // {
            //     nums[i]=nums[i/2]+nums[i/2+1];
            // }
            maxval=maxval>nums[i]?maxval:nums[i];
        }
        //sort(nums.begin(),nums.end());
        return maxval;
    }
};
// @lc code=end

