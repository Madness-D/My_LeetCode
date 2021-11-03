/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
    // //暴力法,最后一个超时了
    // int ans = 0;
    // int size = height.size();
    // for (int i = 1; i < size - 1; i++) {
    //     int max_left = 0, max_right = 0;
    //     for (int j = i; j >= 0; j--) { //Search the left part for max bar size
    //         max_left = max(max_left, height[j]);
    //     }
    //     for (int j = i; j < size; j++) { //Search the right part for max bar size
    //         max_right = max(max_right, height[j]);
    //     }
    //     ans += min(max_left, max_right) - height[i];
    // }
    // return ans;

    //让我们顶峰相遇,双指针法
    int n=height.size();
    int left=0, right=n-1,level=0;//level
    int res=0;
    while(left<right){
        int lower=height[height[left]<height[right]?left++:right--];
        level=max(level,lower);
        res+=level-lower;
    }
    return res;
    }
};
// @lc code=end

