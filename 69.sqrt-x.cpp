/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        //一个简单的想法,相当于从1～x, 找到n,使得n^2<=x, (n+1)^2>x
        int l=1,r=x;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(x/mid==mid) return mid;
            else if(x/mid>mid) l=mid+1;
            else r=mid-1;
        }
        return r;
    }
};
// @lc code=end

