/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
//BFS和DFS都可以做
//BFS，枚举每一个元素，为0：跳过；为1则BFS查询相邻的4个位置(不出界)，如为1则继续查询，直到整个块(岛屿)查询完毕。
//查询过的岛屿置0
//岛屿的数量就是进行BFS的数量
class Solution {
private:
    //感染函数，将x，y所在的岛屿都置0
    void dfs(vector<vector<char>>& grid,int x,int y){
        int n=grid.size(),m=grid[0].size();

        grid[x][y]='0';
        if(x-1>=0 && grid[x-1][y]=='1') dfs(grid,x-1,y);
        if(x+1<n && grid[x+1][y]=='1') dfs(grid,x+1,y);
        if(y-1>=0 && grid[x][y-1]=='1') dfs(grid,x,y-1);
        if(y+1<m && grid[x][y+1]=='1') dfs(grid,x,y+1);
    }
public:
    //DFS
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int res=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
               if(grid[r][c]=='1'){
                   res++;
                   dfs(grid,r,c);
               }
            }
        }
        return res;
    }


//BFS
    // int numIslands(vector<vector<char>>& grid) {
    //     int n=grid.size(),m=grid[0].size();
    //     int res=0;
    //     for(int r=0;r<n;r++){
    //         for(int c=0;c<m;c++){
    //             if(grid[r][c]=='1'){
    //                 ++res;
    //                 grid[r][c]='0';//置0
    //                 queue<pair<int,int> > neighbors;//BFS 队列
    //                 neighbors.push({r,c});//第一个元素入队
    //                 while(!neighbors.empty()){// 如果队列非空
    //                     pair rc=neighbors.front();//访问队首元素
    //                     neighbors.pop();
    //                     int row=rc.first,col=rc.second;
    //                     //接下来遍历四个方向的元素，将邻居置0
    //                     if(row>=1 && grid[row-1][col]=='1'){
    //                         neighbors.push({row-1,col});
    //                         grid[row-1][col]='0';
    //                     }
    //                     if(row+1<n && grid[row+1][col]=='1'){
    //                         neighbors.push({row+1,col});
    //                         grid[row+1][col]='0';
    //                     }
    //                     if(col>=1 && grid[row][col-1]=='1'){
    //                         neighbors.push({row,col-1});
    //                         grid[row][col-1]='0';
    //                     }
    //                     if(col+1<m && grid[row][col+1]=='1'){
    //                         neighbors.push({row,col+1});
    //                         grid[row][col+1]='0';
    //                     }                                                
    //                 }
    //             }
    //         }
    //     }
    //     return res;
    // }


};
// @lc code=end

