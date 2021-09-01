/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
//349，重复返回即可，考虑用set
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1,s2;
        for(int n1:nums1)//新标准下的for循环写法
            s1.insert(n1);
        for(int n2:nums2)
            s2.insert(n2);
        return fun1(s1,s2);
    }
    vector<int> fun1(set<int>& s1,set<int>& s2){
        if(s1.size() >s2.size()){return fun1(s2,s1);} 
        vector<int> res;
        for(auto iter=s1.begin();iter!=s1.end();++iter){
            if(s2.find(*iter)!=s2.end()){res.push_back(*iter);}
        }
        return res;
    }

};
// @lc code=end

