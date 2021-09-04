/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        //如果一个字母出现的次数是i，为偶数，那么res+=i
        //i为奇数的,res+=i-1
        //利用hash表，本来想利用数组存储，但ASCII码，大写字母和小写字母不连续
        int len=s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<len;i++){
            mp[s[i]]++;
        }
        int res=0,flag=0;
        for(auto mm:mp){
            // if(mm.second%2==0){
            //     res+=mm.second;
            // }
            // if(mm.second%2==1){
            //     res+=mm.second-1;
            //     flag=1;
            // }
            res+=mm.second/2*2;
            if(mm.second%2==1){flag=1;}
        }
        if(flag) res++;
        return res;
        

    }
};
// @lc code=end

