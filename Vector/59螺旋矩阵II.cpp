/* ************************************************************************
> File Name:     59螺旋矩阵II.cpp
> Author:        bwding
>  mail:         dingbuowen@outlook.com
> Created Time:  Thu 28 Apr 2022 04:49:32 PM CST
> link:          https://leetcode-cn.com/problems/spiral-matrix-ii/
> Description:   给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
> 思路：         单纯的模拟，这里是按层模拟。直接复制粘贴的代码
 ************************************************************************/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        vector<vector<int>> matrix(n, vector<int>(n));
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                matrix[top][column] = num;
                num++;
            }
            for (int row = top + 1; row <= bottom; row++) {
                matrix[row][right] = num;
                num++;
            }
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    matrix[bottom][column] = num;
                    num++;
                }
                for (int row = bottom; row > top; row--) {
                    matrix[row][left] = num;
                    num++;
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return matrix;

    }
};
