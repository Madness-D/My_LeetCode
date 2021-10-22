/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // //哈希表
        // unordered_map<int,int> mp;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // int n=nums.size()/3;
        // vector<int> ans;
        // for(auto it=mp.begin();it!=mp.end();it++){
        //     if(it->second>n) ans.push_back(it->first);
        // }
        // return ans;

        // //排序,有点问题
        // sort(nums.begin(),nums.end());
        // int len=nums.size();
        // int n=nums.size()/3;
        // vector<int> ans;
        // // if(nums[0]==nums[n])
        // //     ans.push_back(nums[0]);
        // //     //下面这句，如果size是1，nums.size()-n=1，越界
        // // if(nums[nums.size()-1]==nums[nums.size()-n])
        // //     ans.push_back(nums[nums.size()-1]);
        // // return ans;
        // if(nums.size()==2 && nums[0]!=nums[1])
        //     return nums;
        // int cnt1=0,cnt2=0;
        // for(int num:nums){
        //     if(num==nums[n])
        //         cnt1++;
        //     if(num==nums[2*n])
        //         cnt2++;
        // }
        // if(cnt1>n)
        //     ans.push_back(nums[n]);
        // if(cnt2>n && nums[n]!=nums[2*n])
        //     ans.push_back(nums[2*n]);
        // return ans;

        //摩尔投票法
    }
};
// @lc code=end

