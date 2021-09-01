/*
 * @lc app=leetcode.cn id=881 lang=cpp
 *
 * [881] 救生艇
 */

// @lc code=start
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int len=people.size();
        sort(people.begin(),people.end());
        int left=0,right=len-1;
        int res=0;
        while(left<=right){//不填=.可能最后中间两个需要两个船，但只res++一次
            if(people[left]+people[right]>limit){
                res++;
                right--;
            }else{
                res++;
                left++;
                right--;
            }
        }

    return res;
    }
};
// @lc code=end

