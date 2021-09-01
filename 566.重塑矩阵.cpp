/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
//
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size();
        int n=mat[0].size();
        if(r*c!=m*n){return mat;}
        // vector<vector<int>> res(r, vector<int>(c));
        // int p1=0,p2=0;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
                
        //         if(p2==c){//p2++了，因此是==c，不是c-1
        //             p1++;p2=0;
        //         }
        //         res[p1][p2]=mat[i][j];
        //         p2++;
        //     }
        // }
        // return res;
        
        //官方题解
         vector<vector<int>> ans(r, vector<int>(c));
        for (int x = 0; x < m * n; ++x) {
            ans[x / c][x % c] = mat[x / n][x % n];
        }
        return ans;

        
    }
};
// @lc code=end

