/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

// @lc code=start
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        //暴力法，两重循环
        //一个哈希表，key是距离平方，value是出现次数
        //设出现次数为m，是一个排列问题，m中取两个排列，即m(m-1)
    int res=0;

    for(int i=0;i<points.size();i++){
        unordered_map<int,int> mp;

        for(int j=0;j<points.size();j++){
            int dis=(points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
            mp[dis]++;
        }

        //unordered_map<int,int>::iterator iter;
        for(auto iter=mp.begin();iter!=mp.end();iter++){
            res+=iter->second*(iter->second-1);
        }

    }
    return res;

    }
};
// @lc code=end

