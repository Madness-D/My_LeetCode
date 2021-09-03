/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len=nums.size();
        // //是子序列，不是子串，gg
        // for(int i=0;i<len-2;i++){
        //     if(nums[i]<nums[i+1]&&nums[i+1]<nums[i+2])
        //         return true;
        // }
        // return false;

        //nums = [2,1,5,0,4,6];  1,5,6和 0，4，6都符合条件
        if(len<3) return false;
        int small=INT_MAX,mid=INT_MAX;
        for(int n:nums){
            if(n<=small){//需要有=，例如1 1 6，不符合条件
                small=n;
                //只更新small,而不更新mid，为什么？
                //考虑4，6，1，2，3
                //s=4,m=6
                //s=1,m=6//这个时候如果不更新small，不会发现后面的123这个符合条件的
                // //而且更新small而不更新mid，暗含了mid前面有一个比mid小的数，这样如果1后面是一个7，也能return true
                //s=1,m=2
            }else if(n<=mid){
                mid=n;
            }else if(n>mid){
                return true;
            }
        }
        return false;

    }
};
// @lc code=end

