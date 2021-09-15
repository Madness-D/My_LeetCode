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

        // //返回最大值
        // //max_element 返回的是地址  复杂度O(n)
        // return max_element(nums.begin(), nums.end()) - nums.begin();

        //二分法,遇到要求O(logn)的一般都是二分
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[mid+1]) r=mid;
            else l=mid+1;
        }
        return r;
    }
};
// @lc code=end

