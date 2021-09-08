/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //要求不使用额外的空间，一般将原数组作为hash表使用
        int n=nums.size();//
        for(auto nu:nums){
            //比如说2出现了，将nums[2]+=n
            //x可能是已经增加过的，需要将其还原为[1,n]的数
            int x=(nu-1)%n ;
            nums[x]+=n;
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
};
// @lc code=end

