/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //暴力捏
        int len1=nums1.size(),len2=nums2.size();
        vector<int> res;
        for(int i=0;i<len1;i++){
            int pos=0;
            for(int j=0;j<len2;j++){
                if(nums2[j]==nums1[i]){
                    pos=j;
                    break;
                }
            }
            int temp=pos;
            for(temp;temp<len2;temp++){
                if(nums2[temp]>nums1[i]){
                    break;
                }
            }
            res.push_back(temp<len2?nums2[temp]:-1);
        }
        return res;
    }
};
// @lc code=end

