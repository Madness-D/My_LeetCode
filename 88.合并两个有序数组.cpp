/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,index=0;//index为c的长度，函数返回值
        vector<int> temp(m+n,0);//初始定义vector长度，否则会越界
    while(i<m && j<n){
        if(nums1[i]<=nums2[j]){
            temp[index++]=nums1[i++];//c[index]=a[i];i++;index++;
        }else{
            temp[index++]=nums2[j++];
        }
    }
    while(i<m) temp[index++]=nums1[i++];
    while(j<n) temp[index++]=nums2[j++];
    nums1=temp;
    }
};
// @lc code=end

