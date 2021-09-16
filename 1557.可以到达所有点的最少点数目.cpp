/*
 * @lc app=leetcode.cn id=1557 lang=cpp
 *
 * [1557] 可以到达所有点的最少点数目
 */

// @lc code=start
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        //按照提示,只要所有找到入度为0的点就行
        vector<int> inde(n,0);
        for(int i=0;i<edges.size();i++){
            inde[edges[i][1]]++;
        }
        vector<int> res;
        for(int i=0;i<inde.size();i++){
            if(inde[i]==0){
                res.push_back(i);
            }
        }
        return res;

    }
};
// @lc code=end

