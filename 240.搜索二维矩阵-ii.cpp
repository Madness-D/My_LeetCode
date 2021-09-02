/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        //暴力
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]==target) return true;
        //     }
        // }
        // return false;
        
        //从左下角开始。如果>target,上移；如果<target，右移
        int h=m-1,l=0;
        while(h>=0 && l<n){ //&&,不是||，
            if(matrix[h][l]==target) return true;
            else if(matrix[h][l]<target) l++;
            else if(matrix[h][l]>target) h--;
        }
        return false;
    }
};
// @lc code=end

