/*
https://leetcode-cn.com/problems/binary-search/
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len=nums.size();
        int l=0,r=len-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) l=mid+1;
            else r=mid-1;
        }
        return -1;

    }
};