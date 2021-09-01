/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len=nums.size();
        if(len<3) return {};
        sort(nums.begin(),nums.end());

        if(nums[0]>0) return {};

        vector<vector<int>> res;
        for(int i=0;i<len;i++){
            // if(nums[i]>0) return res;
            // 去重：如果此数已经选取过，跳过
            if (i > 0 && nums[i] == nums[i-1])  continue;

            int l=i+1,r=len-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum>0){r--;}
                else if(sum<0){l++;}
                else {
                    res.push_back({nums[i],nums[l],nums[r]});
                    l++;r--;
                    //去重，防止后面两个数字重复
                    while (l < r && nums[l] == nums[l-1])  l++;
                    while (l < r && nums[r] == nums[r+1])    r--;
                    }
            }
        }
        return res;

    }
};
// @lc code=end

