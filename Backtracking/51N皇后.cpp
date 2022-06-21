/* ************************************************************************
> File Name:		51N皇后.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-21 20:38:04
> Link:		https://leetcode.cn/problems/n-queens/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>> ans;
    void backtracking(int n,int r,vector<string> &partans){
        if(r==n){
            ans.emplace_back(partans);
            return;
        }
        //每一行的每一个位置，合法就向下递归
        for(int c=0;c<n;c++){
            if(isValid(r,c,partans,n)){
                partans[r][c]='Q';
                backtracking(n,r+1,partans);//递归下一层
                partans[r][c]='.';
            }
        }
    }

    bool isValid(int row, int col, vector<string>& chessboard, int n) {
        // 检查列
        for (int i = 0; i < row; i++) { // 这是一个剪枝
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }
        // 检查 45度角是否有皇后
        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        // 检查 135度角是否有皇后
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
    vector<string> partans(n,string(n,'.'));

        backtracking(n,0,partans);
        return ans;
    }
};