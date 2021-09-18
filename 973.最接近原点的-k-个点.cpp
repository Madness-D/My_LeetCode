/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {


    //神奇的STL
    nth_element(points.begin(),points.begin()+k,points.end(), [](auto&& l, auto&& r){return l[0]*l[0]+l[1]*l[1]<r[0]*r[0]+r[1]*r[1];});
        points.resize(k);
        return points;
    }
};
// @lc code=end

