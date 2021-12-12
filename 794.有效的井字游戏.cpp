/*
 * @lc app=leetcode.cn id=794 lang=cpp
 *
 * [794] 有效的井字游戏
 */

// @lc code=start
class Solution {
        //x==o||x==o+1 
        //x与o不能同时赢
        //x赢，则x==o+1
        //o赢，则x==o
    bool isWin(vector<string>& board, char ch){
        for(int i=0;i<3;i++){
            if(board[i][0]==ch && board[i][1]==ch && board[i][2]==ch) return true;
            if(board[0][i]==ch && board[1][i]==ch && board[2][i]==ch) return true;
        }
        if(board[0][0]==ch && board[1][1]==ch && board[2][2]==ch) return true;
        if(board[0][2]==ch && board[1][1]==ch && board[2][0]==ch) return true;
        return false;
    }
public:
    bool validTicTacToe(vector<string>& board) {
        int ocnt=0,xcnt=0;
        for(string s:board){
        for(char ch:s){
            if(ch=='X') xcnt++;
            if(ch=='O') ocnt++;
        }}
        if(xcnt!=ocnt && xcnt!=ocnt+1) return false;
        if(isWin(board,'X') && isWin(board,'O')) return false;
        if(isWin(board,'X') && xcnt!=ocnt+1) return false;
        if(isWin(board,'O') && xcnt!=ocnt) return false;
        return true;
    }
};
// @lc code=end

