/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
       vector<vector<int> > res(rowIndex+1);
        for(int i=0;i<=rowIndex;i++){
            res[i].resize(i+1);//第i行有i+1个元素
            res[i][0]=1,res[i][i]=1;
            for(int j=1;j<i;j++){
                res[i][j]=res[i-1][j-1]+res[i-1][j];
            }
        }
        // vector<int> resul(rowIndex+1);
        // resul=res[rowIndex];
        return res[rowIndex];
    }
};
// @lc code=end

