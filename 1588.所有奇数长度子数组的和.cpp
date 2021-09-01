/*
 * @lc app=leetcode.cn id=1588 lang=cpp
 *
 * [1588] 所有奇数长度子数组的和
 */

// @lc code=start
//accumulate(v.begin(),v.end())
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        //暴力
        //accumulate复杂度O(n)
        // 整体复杂度O(n^3)
        // int sum=0;
        // for(int i=0;i<n;i+=2){
        //     for(int j=0;j+i<n;j++){
        //         sum+=accumulate(arr.begin()+j,arr.begin()+j+i+1,0);
        //     }
        // }
        // return sum;

        //Prefix Sum,前缀和
        //不使用accumulate，但本质上仍然一样
        //时间复杂度 O(n^2)
        // vector<int> presum={0};
        // for(int e: arr) presum.push_back(presum.back() + e);
        // int res=0;
        // for(int i=0;i<n;i++){
        //     for(int j=1;i+j-1<n;j+=2){
        //         res+=presum[i+j]-presum[i];
        //     }
        // }
        // return res;

        //计算一个数可以选几次
        //left=i+1//0、1、……
        //right=n-i
        //一个数，一共在left_even * right_even + left_odd * right_odd个奇数数组中出现
        //left_even = (left + 1) / 2，left_odd = left / 2
        //right_even = (right + 1) / 2，right_odd = right / 2
        int res=0;
        for(int i=0;i<n;i++){
            int left=i+1,right=n-i,
            left_even=(left+1)/2,right_even=(right+1)/2,
            left_odd=left/2,right_odd=right/2;
            res+=arr[i]*(left_even*right_even+left_odd*right_odd);
        }
        return res;


    }
};
// @lc code=end

