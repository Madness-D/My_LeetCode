/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
//bfs，第i层就是距离i
class Solution {
    //错误
//     bool fun(vector<vector<int>>& mat,int r,int c){//判断邻居是否有0，有则返回true
//     int m=mat.size(),n=mat[0].size();
//     if((r-1>=0 && !mat[r-1][c])||(r+1<m && !mat[r+1][c])||(c-1>=0 &&!mat[r][c-1])||(c+1<n&&!mat[r][c+1]))
//     return true;
//     else return false;

//     }
// public:

//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int m=mat.size(),n=mat[0].size();
//         vector<vector<int> > res;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(!mat[i][j]) res[i][j]=0;
//                 else{
//                     int dist=0;
//                     queue<pair<int,int> > neighbors;
//                     neighbors.push({i,j});
//                     while(!neighbors.empty()){
//                         pair rc=neighbors.front();
//                         neighbors.pop();
//                         int row=rc.first,col=rc.second;
//                         if(fun(mat,row,col)){
//                             dist++;break;}
//                         else{//周围全是1
//                             dist++;
//                             if(row-1>=0) neighbors.push({row-1,col});
//                             if(row+1<m) neighbors.push({row+1,col});
//                             if(col-1>=0) neighbors.push({row,col-1});
//                             if(col+1<n) neighbors.push({row,col+1});
//                         }
//                     }
//                     res[i][j]=dist;

//                 }
//             }
//         }

//     return res;
//}

private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<int>> seen(m, vector<int>(n));
        queue<pair<int, int>> q;
        // 将所有的 0 添加进初始队列中
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    q.emplace(i, j);
                    seen[i][j] = 1;
                }
            }
        }

        // 广度优先搜索
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj]) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.emplace(ni, nj);
                    seen[ni][nj] = 1;
                }
            }
        }

        return dist;}
};
// @lc code=end

