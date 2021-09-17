/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
class Solution {
public:
    vector<int> vis;
    int num;

    void dfs(vector<vector<int>>& rooms, int x) {
        vis[x] = true;
        num++;
        for (auto& it : rooms[x]) {
            if (!vis[it]) {
                dfs(rooms, it);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // //本质上就是遍历图,看是不是连通图
        // //整一个vist数组,从0开始遍历,看能否visit所有的n个房间

        //BFS,队列
        //int n=rooms.size(),num=0;//num记录可及room数
        // vector<int> vis(n);
        // queue<int> qu;
        // vis[0]=1;//0号房间一定可以访问
        // qu.emplace(0);//0号房入队
        // while(!qu.empty()){
        //     int temp=qu.front();
        //     qu.pop();
        //     num++;
        //     for(int i=0;i<rooms[temp].size();i++){// 遍历temp房间的钥匙
        //         if(!vis[rooms[temp][i]]){
        //             vis[rooms[temp][i]]=1;
        //             qu.emplace(rooms[temp][i]);
        //         }
        //     }
        // }
        // return num==n;

        //DFS,使用DFS函数
         int n=rooms.size();
         num=0;
        vis.resize(n);
        dfs(rooms, 0);
        return num == n;

    }
};
// @lc code=end

