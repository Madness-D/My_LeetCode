/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // //来一个暴力的方法
        // vector<int> nums;
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[0].size();j++)
        //     nums.push_back(matrix[i][j]);
        // }
        // sort(nums.begin(),nums.end());
        // return nums[k-1];

        //优先队列，最大堆
        priority_queue<int> pq;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++)
            pq.push(matrix[i][j]);
        }
        while(pq.size()!=k)
            pq.pop();
        return pq.top();

    }
};
// @lc code=end

