/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len=nums.size();
        if(len<3) return {};

        // //暴力法
        // int res=nums[0]+nums[1]+nums[2];
        // for(int i=0;i<len-2;i++){
        //     for(int j=i+1;j<len-1;j++){
        //         for(int k=j+1;k<len;k++){
        //             int temp=nums[i]+nums[j]+nums[k];
        //             if(abs(temp-target)<abs(res-target)){
        //                 res=temp;
        //             }
        //         }
        //     }
        // }
        // return res;

        //排序后双指针
        sort(nums.begin(),nums.end());
        int res=nums[0]+nums[1]+nums[2];
        for(int i=0;i<len-2;i++){
            int l=i+1,r=len-1;
            while(l<r){
                int temp=nums[i]+nums[l]+nums[r];
                //更新res
                if(temp==target){
                    return temp;
                }else if(abs(temp-target)<abs(res-target)){
                    res=temp;
                }
                //移动指针
                if(temp<target){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

