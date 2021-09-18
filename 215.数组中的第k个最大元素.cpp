/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 * 使用快排的思路
 */

// @lc code=start
class Solution {
public:
    // int quickSelect(vector<int>& a, int l, int r, int index) {
    //     int q = randomPartition(a, l, r);
    //     if (q == index) {
    //         return a[q];
    //     } else {
    //         return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
    //     }
    // }

    // inline int randomPartition(vector<int>& a, int l, int r) {
    //     int i = rand() % (r - l + 1) + l;
    //     swap(a[i], a[r]);
    //     return partition(a, l, r);
    // }

    // inline int partition(vector<int>& a, int l, int r) {
    //     int x = a[r], i = l - 1;
    //     for (int j = l; j < r; ++j) {
    //         if (a[j] <= x) {
    //             swap(a[++i], a[j]);
    //         }
    //     }
    //     swap(a[i + 1], a[r]);
    //     return i + 1;
    // }

    int findKthLargest(vector<int>& nums, int k) {

        ////快排
        // srand(time(0));
        // return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);

    //     //调用sort函数
    // sort(nums.begin(),nums.end());
    // return nums[nums.size()-k];

    //堆，调用优先队列
    //全部存入优先队列，然后popk次
    //priority_queue<int,vector<int>,less<int>> maxHeap;
    // priority_queue<int> maxHeap;
    // for(int i=0;i<nums.size();i++){
    //     maxHeap.push(nums[i]);
    // }
    // for(int i=0;i<k-1;i++){
    //     maxHeap.pop();
    // }
    // return maxHeap.top();



    
    }
};

// @lc code=end

