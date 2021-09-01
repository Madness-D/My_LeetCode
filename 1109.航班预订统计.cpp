/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n);
        int len=bookings.size();

        //暴力 超时
        // for(int i=0;i<len;i++){
        //     for(int j=bookings[i][0]-1;j<bookings[i][1];j++){
        //         res[j]+=bookings[i][2];
        //     }
        // }

        //差分数组
        for(auto booking:bookings){
            res[booking[0]-1]+=booking[2];
            if(booking[1]<n){
            res[booking[1]]-=booking[2];
            }
        }

        for(int i=1;i<n;i++){
            res[i]+=res[i-1];
        }
        return res;
    }
};
// @lc code=end

