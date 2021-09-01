/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
//
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //合并数组，合并的复杂度为O(m+n)
        int m=nums1.size(),n=nums2.size();
        int newlen=m+n;
        vector<int> merge(newlen);
        int i=0,j=0,index=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                merge[index++]=nums1[i++];
            }else{
                merge[index++]=nums2[j++];
            }
        }
        if(i==m){
            for(int k=j;k<n;k++){
                merge[index++]=nums2[k];
            }
        }else if(j==n){
            for(int k=i;k<m;k++){
                merge[index++]=nums1[k];
            }
        }

        int mid=(newlen-1)/2;
        return newlen%2==0?(double)(merge[mid]+merge[mid+1])/2:merge[mid];

        //题目要求的复杂度为O(log(m+n))，只能用二分的思路
        

    }
};
// @lc code=end

