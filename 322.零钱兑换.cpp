/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
            //贪心吧,先把conis从大到小排序
            //错了, 不是贪心,有些贪心会凑不齐, 但是其实是可以的
        sort(coins.begin(),coins.end(),greater<int>());
        int res=0;
        for(int co:coins){
            if(amount>=co){
                int n=amount/co;
                amount-=n*co;
                res+=n;
            }
        }
        if(amount==0) return res;
        else return -1;
    }
};
// @lc code=end

