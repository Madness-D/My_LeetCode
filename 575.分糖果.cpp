/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

// @lc code=start
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        // //要求,数量上均分,种类上最多
        // //哈希表来一个
        // unordered_map<int,int> mp;
        // int n=candyType.size();
        // int owned=0;
        // for(int num:candyType){
        //     mp[num]++;
        // }
        // for(auto& pa:mp){
        //     owned++;
        //     if(owned>=n/2){
        //         break;
        //     }
        // }
        // return owned;

    
        return min(unordered_set<int>(candyType.begin(), candyType.end()).size(), candyType.size() / 2);


    }
};
// @lc code=end

