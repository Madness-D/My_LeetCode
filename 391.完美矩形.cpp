/*
 * @lc app=leetcode.cn id=391 lang=cpp
 *
 * [391] 完美矩形
 */

// @lc code=start
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        //完美矩形条件: 内部顶点坐标成对出现,
            //剩下的四个顶点围成的大矩形面积==小矩形面积之和
        //
        //统计小矩形面积，更新左下右上四个值（左下找最小，右上找最大）；
        //把每次遍历到的矩形四点坐标放入set中，重复的就去除；
        //观察set中是否剩下四个坐标，并且四个坐标是满足左下右上四个值组合起来的；
        //3满足且大小矩形面积相等返回true，不满足返回false。

      // 定义总面积和左右上下四个定位坐标
        int sumArea = 0;
        int left = INT_MAX;
        int low = INT_MAX;
        int right = INT_MIN;
        int high = INT_MIN;
        set<string> s;
        for(vector<int> rectangle : rectangles) {
            //获取坐标
            left = min(left, rectangle[0]);
            low = min(low, rectangle[1]);
            right = max(right, rectangle[2]);
            high = max(high, rectangle[3]);

            // 面积求和
            sumArea += (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]);

            // 将坐标转成string
            string ll = to_string(rectangle[0]) + " " + to_string(rectangle[1]);
            string lr = to_string(rectangle[2]) + " " + to_string(rectangle[1]);
            string hl = to_string(rectangle[0]) + " " + to_string(rectangle[3]);
            string hr = to_string(rectangle[2]) + " " + to_string(rectangle[3]);

            // 放入set中,如果有就移除 没有就加入
            if(!s.count(ll)) s.insert(ll);
            else s.erase(ll);
            if(!s.count(lr)) s.insert(lr);
            else s.erase(lr);
            if(!s.count(hl)) s.insert(hl);
            else s.erase(hl);
            if(!s.count(hr)) s.insert(hr);
            else s.erase(hr);
        }

        string ll = to_string(left) + " " + to_string(low);
        string lr = to_string(right) + " " + to_string(low);
        string hl = to_string(left) + " " + to_string(high);
        string hr = to_string(right) + " " + to_string(high);

        // 判断是否只剩下四个并且打矩形面积等于小矩形面积之和
        if(s.size() == 4 && s.count(ll) && s.count(lr) && s.count(hl) && s.count(hr)) {
            return sumArea == (high - low) * (right - left);
        }
        return false;
    }
};
// @lc code=end

