/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */

// @lc code=start
class Solution {
public:


    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {


    // //神奇的STL
    // nth_element(points.begin(),points.begin()+k,points.end(), [](auto&& l, auto&& r){return l[0]*l[0]+l[1]*l[1]<r[0]*r[0]+r[1]*r[1];});
    //     points.resize(k);
    //     return points;


        // //堆，优先队列
        // //将点存储为pair
        typedef pair<int, pair<int,int> > pi;
        priority_queue<pi, vector<pi>, greater<pi> > pq;
        vector<vector<int>> ans;
        for(auto v : points){
            int x = v[0], y = v[1];
            int distance = x*x + y*y;
            pq.push( { distance, {x,y} } );
        }

        while( !pq.empty() && k-- ) {
            auto it = pq.top();
            ans.push_back( {it.second.first, it.second.second });
            pq.pop();
        }

        return ans;
    }
};
// @lc code=end

