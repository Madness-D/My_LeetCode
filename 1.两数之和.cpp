/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *思路：先排序，然后双指针
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
    //     //错误，给出的数组不是有序的，排序后注意需要记录原始的下标
    //     vector<int> ans;
    //     vector<int> temp;
    //     temp=nums;
    //     sort(temp.begin(),temp.end());
    //     int i=0,j=nums.size()-1;
    //     while(i<j){
    //         if(temp[i]+temp[j]==target){
    //             break;
    //         }else if(nums[i]+nums[j]<target){
    //             i++;
    //         }else{
    //             j--;
    //         }
    //     }

    //     if(i<j){
    //   for(int k=0;k<temp.size();k++){
    //       if(i<temp.size()&&nums[k]==temp[i]){
    //           ans.push_back(k);
    //           i=temp.size();
    //       }
    //      else if(j<temp.size()&&nums[k]==temp[j]){
    //           ans.push_back(k);
    //           j=temp.size();
    //       }
    //       if(i==temp.size()&&j==temp.size())return ans;
    //   }
    //   }
    //     return ans;

    //受560启发，hash
    unordered_map<int, int> mp;
    for(int i=0;i<nums.size();i++){
        if(mp.find(target-nums[i])!=mp.end()){
            return{i,mp[target-nums[i]]};
        }
        mp[nums[i]]=i;
    }
    return {};
    }
};
// @lc code=end

