/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
        int res=0;
        int curr=i;
        while(curr){
            curr&=curr-1;
            res++;
        }
        ans.push_back(res);
        }
        return ans;
    }
};
// @lc code=end

