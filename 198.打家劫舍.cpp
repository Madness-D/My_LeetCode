/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
//不能奇、偶分别相加，如1001，答案应该是2
//dp dp[i]=max{nums[i]+dp[i-2],dp[i-1]}
//边界，dp[1]=nums[1];dp[2]=max{nums[1],nums[2]};
//dp[0]=0?
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){return 0;}
        if(nums.size()==1){return nums[0];}
        // if(nums.size()==2){return max(nums[0],nums[1]);}

        //初始化，分别是dp[0],dp[1]
        int v1=nums[0],v2=max(nums[0],nums[1]);

        for(int i=2;i<nums.size();i++){
            int temp=v2;
            v2=max(nums[i]+v1,temp);//dp[i]=max(nums[i]+dp[i-2],dp[i-1])
            v1=temp;//向后遍历
        }
    return v2;
    }
};
// @lc code=end

