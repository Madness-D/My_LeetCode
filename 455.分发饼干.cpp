/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gg=0,ss=0;
        while(gg<g.size()&&ss<s.size()){
            if(g[gg]<=s[ss])
                gg++;// 如果一个孩子的胃口被满足，则gg++
            ss++;//无论是否满足，饼干都要++
        }
        return gg;
    }
};
// @lc code=end

