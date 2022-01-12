/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        if(!n) return 0;
        vector<int> ans(n,0);
        ans[0]=1;
        int i=0,j=0,k=0;//三指针,分别指向*2,*3,*5的
        for(int p=1;p<n;p++){
            int t=min(ans[i]*2,min(ans[j]*3,ans[k]*5));
            if(t==ans[i]*2)  i++;
            if(t==ans[j]*3) j++;
            if(t==ans[k]*5) k++;
            ans[p]=t;
        }
        return ans[n-1];
    }
};
// @lc code=end

