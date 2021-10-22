/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
class Solution {
public:
bool check(vector<vector<int>>& matrix, int mid, int k, int n) {
        int i = n - 1;
        int j = 0;
        int num = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                num += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return num >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // //来一个暴力的方法
        // vector<int> nums;
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[0].size();j++)
        //     nums.push_back(matrix[i][j]);
        // }
        // sort(nums.begin(),nums.end());
        // return nums[k-1];

        // //优先队列，最大堆
        // priority_queue<int> pq;
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[0].size();j++)
        //     pq.push(matrix[i][j]);
        // }
        // while(pq.size()!=k)
        //     pq.pop();
        // return pq.top();

        // //归并排序
        //   struct point {
        //     int val, x, y;
        //     point(int val, int x, int y) : val(val), x(x), y(y) {}
        //     bool operator> (const point& a) const { return this->val > a.val; }
        // };
        // priority_queue<point, vector<point>, greater<point>> que;
        // int n = matrix.size();
        // for (int i = 0; i < n; i++) {
        //     que.emplace(matrix[i][0], i, 0);
        // }
        // for (int i = 0; i < k - 1; i++) {
        //     point now = que.top();
        //     que.pop();
        //     if (now.y != n - 1) {
        //         que.emplace(matrix[now.x][now.y + 1], now.x, now.y + 1);
        //     }
        // }
        // return que.top().val;

        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (check(matrix, mid, k, n)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;

    }
};
// @lc code=end

