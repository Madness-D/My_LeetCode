/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // vector<string> res;
        // if (s.length() < 10) {
        //     return res;
        // }
        // int L = 10;
        // set<string> _set;
        // for (int i = 0; i < s.length() - L + 1; ++i) {
        //     string tmp = s.substr(i,10);
        //     if (_set.find(tmp) == _set.end()) {//_set这个集合里没有，则说明是新的，插入_set
        //         _set.insert(tmp);
        //     }else {
        //         //cbegin()和cend()是C++11新增的，它们返回一个const的迭代器，不能用于修改元素
        //         if (find(res.cbegin(),res.cend(),tmp) == res.cend()) {
        //             res.push_back(tmp);
        //         }
        //     }
        // }
        // return res;

        //思想和上面的一样，滑动窗口遍历
        unordered_set<string> once;
        unordered_set<string> second;
        int size = s.size();

        vector<string> res;
        if (size <= 10) return res;

        string temp = s.substr(0, 10);
        once.insert(temp);
        for (int i = 10; i < size; ++i){
            temp.erase(0, 1);
            temp += s[i];
            if (once.count(temp)){
                second.insert(temp);
            }else{
                once.insert(temp);
            }
        }
        vector<string> realResult(second.begin(), second.end());
        return realResult;

    }
};
// @lc code=end

