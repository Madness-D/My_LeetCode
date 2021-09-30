/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int sa=(ax2-ax1)*(ay2-ay1);
        int sb=(bx2-bx1)*(by2-by1);
        //如何判断是否有重叠？投影
        int xx=min(bx2,ax2)-max(bx1,ax1);
        int yy=min(ay2,by2)-max(ay1,by1);
        int sover=(xx>0?xx:0)*(yy>0?yy:0);
        return sa+sb-sover;
    }
};
// @lc code=end

