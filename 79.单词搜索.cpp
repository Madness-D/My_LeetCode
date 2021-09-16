/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
//回溯法
//使用一个bool矩阵标记当前位置为已访问，防止重复遍历
//所有的可能搜索完成后，再将当前的位置修改为未访问，防止干扰其他位置搜索到当前位置

    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;

        int m=board.size(),n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        bool find=false;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                backtracking(i,j,board,word,find,visited,0);
            }
        }
        return find;

    }

    void  backtracking(int i,int j,vector<vector<char>> &board,string & word,bool& find,vector<vector<bool>> &visited,int pos){
        if(i<0||i>=board.size()||j<0||j>=board[0].size()){//如果i或j超出范围
            return ;
        }
        if(visited[i][j]||find||board[i][j]!=word[pos]){
            //如果board[i][j]已经被访问、或者已经找齐了单词、或者该位置不是想要的字母
            return ;
        }
        if(pos==word.size()-1){
            //该字母是单词的最后一个字母，则将find置为true，return
            find=true;
            return;
        }

        visited[i][j]=true;//标记已经访问
        
        //递归访问相邻字符
        backtracking(i+1,j,board,word,find,visited,pos+1);
        backtracking(i-1,j,board,word,find,visited,pos+1);
        backtracking(i,j+1,board,word,find,visited,pos+1);
        backtracking(i,j-1,board,word,find,visited,pos+1);
        visited[i][j]=false;// 将当前结点的状态改成未访问
    } 

};
// @lc code=end

