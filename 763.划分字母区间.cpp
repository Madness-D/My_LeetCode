/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int>b){
        return a.first<b.first;
    }
    vector<int> partitionLabels(string s) {
    //     //思路记录
    //     //hash table，<char,pair<int,int>>,记录每个字符的起始位置、结束位置
    //     //为了方便比较，用vector来存储吧
    //     vector<pair<int, int>> ha(26);
    //     //遍历一遍字符串，记录位置信息
    //     for (int i = 0; i < s.size(); i++) {
    //         int index = s[i] - 'a';
    //         if (ha[index].first==0&&s[0]!=s[i]){
    //             ha[index].first=i;}
    //         if (i < ha[index].first) { ha[index].first = i; }
    //         if (i > ha[index].second) { ha[index].second = i; }
    //     }
    //     sort(ha.begin(), ha.end(), cmp);//按照起始位置排序
    //     int l=ha[0].first,r=ha[0].second;
    //     int len=r-l+1;
    //     vector<int> res;
    //     for(int i=1;i<26;i++){
    //         if(ha[i].first>r){//不重叠，说明有了一个区间，插入答案中
    //             len=r-l+1;
    //             res.push_back(len);
    //             l=ha[i].first;
    //             r=ha[i].second;
    //         }else{
    //             if(ha[i].second>r){r=ha[i].second;}
    //         }
    //     }

    //     if (r == s.size() - 1 ) {
    //         len = r - l + 1;
    //         res.push_back(len);
    //     }
    // return res;


    //官方题解
    //只记录每个字符出现的最后位置
        int last[26];
        int length = s.size();
        //遍历记录每个字符出现的最后位置
        for (int i = 0; i < length; i++) {
            last[s[i] - 'a'] = i;
        }
        vector<int> partition;

        int start = 0, end = 0;
        for (int i = 0; i < length; i++) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) {//表面i之前的所有的字符的最后位置都在end位置及之前
                partition.push_back(end - start + 1);
                start = end + 1;//进入下一个区间
            }
        }
        return partition;
    }
};
// @lc code=end

