/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    //if(m==0||n==0) return{};
    vector<int> res;
    for (int sum = 0; sum <= m + n - 2; sum++) {
        if (sum % 2 == 0) {//从左下向右上
        // for(int y=0;y<=sum;y++){
        ////这里的条件出错了，没考虑右下部份的情况即8，6这种，不是从第一列开始
        //     res.push_back(mat[sum-y][y]);
        // }
            int y = sum - m + 1 > 0 ? sum - m + 1 : 0;
            for (; y <=sum && sum-y<m&&y<n; y++) {
                res.push_back(mat[sum - y][y]);
            }
        }
        else {
            // for(int x=0;x<=sum;x++){
            //     res.push_back(mat[x][sum-x]);
            // }
            int x = sum - n + 1 > 0 ? sum - n + 1 : 0;
            for (; x <=sum && sum-x<n&&x<m; x++) {
                res.push_back(mat[x][sum - x]);
            }
        }
    }

    return res;
    }
};
// @lc code=end

