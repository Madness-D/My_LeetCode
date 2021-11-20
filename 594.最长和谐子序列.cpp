/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res=0;
       unordered_map<int,int> mp;
       for(int num:nums){
           mp[num]++;
       }
        for(auto [num,cnt]:mp){
            if(mp.count(num-1)){//防止如[1,1,1,1]的情况,会返回4
            int temp=mp[num-1]+cnt;
            res=res>temp?res:temp;
            }
        }
        return res;

    }
};
// @lc code=end

