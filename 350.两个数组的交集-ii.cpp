/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
/*哈希表
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return intersect(nums2,nums1);}
        vector<int> res;
        unordered_map<int,int> mp;
        for(int n1:nums1){
            mp[n1]++;
        }
        for(int n2:nums2){
            if(mp[n2]){
                res.push_back(n2);
                mp[n2]--;
               // if(mp[n2]==0)
                 //   mp.erase(n2);
            }
        }
        return res;
    }
};
*/
//排序，双指针
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int l1=nums1.size(),l2=nums2.size();
        int p1=0,p2=0;
        vector<int> res;
        while(p1<l1 && p2<l2){
//三个if的顺序也有影响
            if(nums1[p1]<nums2[p2]){
                p1++;
            }
            else if(nums1[p1]>nums2[p2]){
                p2++;
            }
            else{
                res.push_back(nums1[p1]);
                p1++;p2++;
            }
        }
        return res;
    }
};
// @lc code=end

