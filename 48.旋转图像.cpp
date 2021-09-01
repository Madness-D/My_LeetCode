/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();

        // //旋转，先转置，再对称
        // //原地转置
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<i;j++){//注意j的范围
        //        swap(matrix[i][j],matrix[j][i]);
        //     }
        // }
        // //对称
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix.size()/2;j++){
        //         swap(matrix[i][j],matrix[i][n-1-j]);
        //     }
        // }

        //本质上，第i行旋转之后为倒数第i列,即matrix[i][j]-->matrix[j][n-1-i]
        //但是直接交换，出错
        //应该是四个边，组成一个循环
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < (n + 1) / 2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }

    }
};
// @lc code=end

