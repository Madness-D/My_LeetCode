/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {

        //sort(nums.begin(),nums.end());

        // //记录0 1 2的个数、重构
        // vector<int> ve(3);
        // for(int i=0;i<nums.size();++i){
        //     ve[nums[i]]++;
        // }
        // for(int i=0;i<ve[0];i++){
        //     nums[i]=0;
        // }
        // for(int i=ve[0];i<ve[0]+ve[1];i++){
        //     nums[i]=1;
        // }
        // for(int i=ve[0]+ve[1];i<nums.size();i++){
        //     nums[i]=2;
        // }

        //单指针，遍历两次
        // int len=nums.size();
        // int head=0,ptr=0;
        // while(ptr<len){
        //     if(nums[ptr]==0){
        //         swap(nums[head],nums[ptr]);
        //         head++;ptr++;
        //     }
        //     else{ptr++;}
        // }
        // ptr=head;
        // while(ptr<len){
        //     if(nums[ptr]==1){
        //         swap(nums[head],nums[ptr]);
        //         head++;ptr++;
        //     }
        //     else{ptr++;}
        // }

        //双指针
        int len=nums.size();
        int l=0,r=len-1;
        for(int i=0;i<=r;i++){
            while(i<=r && nums[i]==2){
                swap(nums[i],nums[r]);
                r--;
            }
            if(nums[i]==0){
                swap(nums[i],nums[l]);
                l++;
            }

        }



    }
};
// @lc code=end

