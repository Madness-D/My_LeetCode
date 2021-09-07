/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        //双指针
        int l=0,r=height.size()-1;
        int maxV=0;
        while(l<r){
            maxV=max(maxV,min(height[l],height[r])*(r-l));
            if(height[l]<=height[r]){
                ++l;
            }else{
                --r;
            }

        }
        return maxV;

    }
};
// @lc code=end

