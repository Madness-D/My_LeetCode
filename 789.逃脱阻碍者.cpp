/*
 * @lc app=leetcode.cn id=789 lang=cpp
 *
 * [789] 逃脱阻碍者
 */

// @lc code=start
//ghosts直接去终点守株待兔是最稳妥的方法
//因此，分别计算起点到终点的距离、ghost到终点的距离
//距离为曼哈顿距离，即x之差+y之差
class Solution {
public:
    int distance(vector<int>& p1,vector<int>& p2){
        return abs(p1[0]-p2[0])+abs(p1[1]-p2[1]);
    }
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        vector<int> source(2);
        int dis1=distance(source,target);
        for(int i=0;i<ghosts.size();i++){
            int dis2=distance(ghosts[i],target);
            if(dis2<=dis1){return false;}
        }
        return true;
    }
};
// @lc code=end

