/*
 * @lc app=leetcode.cn id=407 lang=cpp
 *
 * [407] 接雨水 II
 */

// @lc code=start
class Solution {
public:    struct Node{//存储(x,y)处的格子的最终高度为fh
        int fh, x, y; 
        bool operator< (const Node& t) const {
            return fh > t.fh;
        }
    };
    int dx[4] = {0,-1,0,1}, dy[4] = {1,0,-1,0};
    bool st[210][210]; //访问标记 保证每个格子只更新一次
    int trapRainWater(vector<vector<int>>& h) {
        int n = h.size(), m = h[0].size();
        priority_queue<Node> q;//优先队列 关于最终高度fh的小根堆
        //由于最外一圈格子的最终高度已确定 可以直接加入外层格子集合中
        for(int j = 0; j < m; j++){//最外一圈的上下两行
            st[0][j] = st[n-1][j] = true;
            q.push({h[0][j], 0, j}), q.push({h[n-1][j], n-1, j});
        }
        for(int i = 1; i < n-1; i++){//最外一圈的左右两列
            st[i][0] = st[i][m-1] = true;
            q.push({h[i][0], i, 0}), q.push({h[i][m-1], i, m-1});
        }
        int ans = 0;
        while(q.size()){
            auto [fh, x, y] = q.top(); q.pop();
            ans += fh - h[x][y];
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx<0||nx>=n||ny<0||ny>=m||st[nx][ny]) continue;
                st[nx][ny] = true;
                q.push({max(h[nx][ny],fh),nx,ny});
            }
        }
        return ans;
    }

};
// @lc code=end

