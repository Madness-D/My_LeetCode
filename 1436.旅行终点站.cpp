/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * [1436] 旅行终点站
 */

// @lc code=start
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        //出度为0的就是目标，旅行终点
        //用什么存？
        //最开始只遍历了出发的城市 应该是遍历到达的城市，发现出度为0的是目标
        unordered_set<string> st;
        for(auto path:paths ){
            st.insert(path[0]);
        }
        for(auto path:paths){
            if(!st.count(path[1])){
                return path[1];
            }
        }
        return " ";
    }
};
// @lc code=end

