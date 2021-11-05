/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size();//这里的r不能是n-1  ??
        int mid;
        while(l<r){
            mid=(l+r)/2;
            if(nums[mid]>mid) r=mid;
            else l=mid+1;
        }
    return l;
    }
};
// @lc code=end

