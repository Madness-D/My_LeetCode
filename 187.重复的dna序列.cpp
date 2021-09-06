/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
         vector<string> res;
        if (s.length() < 10) {
            return res;
        }
        int L = 10;
        set<string> _set;
        for (int i = 0; i < s.length() - L + 1; ++i) {
            string tmp = s.substr(i,10);
            if (_set.find(tmp) == _set.end()) {
                _set.insert(tmp);
            }else {
                if (find(res.cbegin(),res.cend(),tmp) == res.cend()) {
                    res.push_back(tmp);
                }
            }
        }
        return res;

    }
};
// @lc code=end

