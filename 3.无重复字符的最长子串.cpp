/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.length();
        if(len==0){return 0;}
        int l=0;//左指针
        set<char> st;//set
        int res=0;
        for(int i=0;i<len;i++){//i为右指针
        while(st.find(s[i])!=st.end()){//st里已有，表示重复
        st.erase(s[l]);//删除重复元素
        l++;//左指针++
        }
        res=max(res,i-l+1);
        st.insert(s[i]);//插入右端新元素
        }
        return res;
    }
};
// @lc code=end

