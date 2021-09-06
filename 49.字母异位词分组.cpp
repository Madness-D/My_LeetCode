/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //排序后就一样了呢
        //排序后的作为key，原单词插入value的数组中
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            string key=strs[i];
            sort(key.begin(),key.end());
            //push_back和emplace_back的区别
            //https://zhuanlan.zhihu.com/p/213853588
            mp[key].emplace_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto iter=mp.begin();iter!=mp.end();++iter){
            ans.emplace_back(iter->second);
        }
        return ans;
    }
};
// @lc code=end

