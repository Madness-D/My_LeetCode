/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // //看错题了,下面的是求最长递增子串
        // int l=0,r=0;
        // int res=0;
        // while(r<nums.size()-1){
        //     if(nums[r]<nums[r+1]){
        //         r++;
        //     }else{
        //         res=res>(r-l+1)?res:(r-l+1);
        //         r++;
        //         l=r;
        //     }
        // }
        // return res;

        // //来一个O(n^2)的
        // //但是 [0,1,0,3,2,3] 会识别013,输出3
        // int res=0;
        // for(int i=0;i<nums.size();i++){
        //     int temp=1; 
        //     int pre=nums[i];
        //     for(int j=i;j<nums.size();j++){
        //         if(nums[j]>pre){
        //             pre=nums[j];
        //             temp++;
        //         }
        //     }
        //     res=res>temp?res:temp;
        // }
        // return res;

    vector<int> res;
    for(int i=0; i<nums.size(); i++) {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if(it==res.end()) res.push_back(nums[i]);
        else *it = nums[i];
    }
    return res.size();

    }
};
// @lc code=end

