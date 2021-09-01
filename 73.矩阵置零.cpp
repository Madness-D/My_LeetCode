/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        //哈希数组，空间复杂度O(m+n)
        // vector<int> rowhash(m,0),colhash(n,0);
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]){continue;}
        //         else{rowhash[i]=1;colhash[j]=1;}
        //     }
        // }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(rowhash[i]||colhash[j]){
        //             matrix[i][j]=0;
        //         }
        //     }
        // }

        //利用第一行和第一列标记该行或该列是否有0出现
        //因为第一行和第一列会被修改，所以需要先遍历一下，用变量记录一下
        int row1=0,col1=0;
        for(int i=0;i<n;i++){
            if(!matrix[0][i]){row1=1;break;}
        }
        for(int i=0;i<m;i++){
            if(!matrix[i][0]){col1=1;break;}
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]){continue;}
                else{matrix[i][0]=0;matrix[0][j]=0;}
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(!matrix[i][0]||!matrix[0][j]){
                    matrix[i][j]=0;
                }
            }
        }

        if(row1){
            for(int i=0;i<n;i++){
            matrix[0][i]=0;}
        }
        
        if(col1){
            for(int i=0;i<m;i++){
            matrix[i][0]=0;}
        }

    }
};
// @lc code=end

