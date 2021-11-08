/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        //两次遍历
        int n=ratings.size();
        vector<int> can(n,1);
        //int summ=n;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                can[i]=can[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1] && can[i]<=can[i+1]){
                can[i]=can[i+1]+1;
            }
        }

        int summ=0;
        for(int num:can){
            summ+=num;
        }
        return summ;
    }
};
// @lc code=end

