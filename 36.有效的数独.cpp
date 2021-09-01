/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    // bool isValidSudoku(vector<vector<char>>& board) {
    //     int a[10]={0};
    //     int i,j,exp=0;
    //     //bool yes=1;
    //     //hang
    //     for(i=0;i<9;i++)
    //     {
    //         for(j=0;j<9;j++)
    //         {
    //             if(board[i][j]=='.')continue;
    //             exp=board[i][j]-'0';
    //             if(a[exp]==1)return false;
    //             else a[exp]=1;
    //         }
    //         memset(a,0,sizeof(a));
    //     }
    //     //lie
    //     for(i=0;i<9;i++)
    //     {
    //         for(j=0;j<9;j++)
    //         {
    //             if(board[j][i]=='.')continue;
    //             exp=board[j][i]-'0';
    //             if(a[exp]==1)return false;
    //             else a[exp]=1;
    //         }
    //         memset(a,0,sizeof(a));
    //     }
    //     //ge
    //     int hang,lie;
    //     for(hang=0;hang<=6;hang+=3)
    //     {
    //         for(lie=0;lie<=6;lie+=3)
    //         {
    //         for(i=0;i<3;i++)
    //         {
    //             for(j=0;j<3;j++)
    //             {
    //                 if(board[i+hang][j+lie]=='.')continue;
    //                 exp=board[i+hang][j+lie]-'0';
    //                 if(a[exp]==1) return false;
    //                 else a[exp]=1;
    //             }            
    //         }
    //         memset(a,0,sizeof(a));       
    //         }
    //     }
    //     return true;
    // }

    //多个哈希表，一次遍历
    //box_index = (row / 3) * 3 + columns / 3
    //box_index:  0:8
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowhash[9][10]={0};
        int colhash[9][10]={0};
        int boxhash[9][10]={0};
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]=='.'){continue;}
                else{
                    int num=board[row][col]-'0';
                    int boxIndex=(row/3)*3+col/3;
                    if(rowhash[row][num]){
                        return false;
                        }else{
                            rowhash[row][num]++;
                        }
                    if(colhash[col][num]){
                        return false;
                        }else{
                            colhash[col][num]++;
                        }
                    if(boxhash[boxIndex][num]){
                        return false;
                        }else{
                            boxhash[boxIndex][num]++;
                        }
                }
            }
        }
    return true;
    }
};
// @lc code=end

