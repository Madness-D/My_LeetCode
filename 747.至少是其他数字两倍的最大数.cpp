/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 */

// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int len=nums.size();
        if(len==1) return 0;

        int first=INT_MIN,second=INT_MIN,fp;
        for(int i=0;i<len;i++){
            if(nums[i]>first){
                second=first;
                first=nums[i];fp=i;
            }else if(nums[i]>second){
                second=nums[i];
            }
        }
        if(first>=2*second) return fp;
        else return -1;
    }
};
// @lc code=end

