/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
class Solution {
public:
    //判断是不是候选字符串
    //双指针， p1 p2;字符相等就都++，不相等就p1++，p2不动
    //最终p2能够到达dic终点，则返回true
    bool islegal(string s,string dic){
        int p1=0,p2=0;
        int l1=s.size(),l2=dic.size();
        while(p1<l1 && p2<l2){
            if(s[p1]==dic[p2]){
                p1++;p2++;
            }else{
                p1++;
            }
        }
        // if(p2==dic.size()-1){
        //     return true;
        // }else{
        //     return false;
        // }
        return p2==dic.size();

    }
    static bool cmp(string s1,string s2){
        if(s1.size()!=s2.size()){
            return s1.size()>s2.size();
        }else{
            return s1.compare(s2)<0;
        }
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        vector<string> res;
        for(int i=0;i<dictionary.size();i++){
            if(islegal(s,dictionary[i])){
                res.push_back(dictionary[i]);
            }
        }
        //此时res内存储的是所有符合条件的字符串
        //接下来排序，首先按照长度排，然后按照字典序排
        sort(res.begin(),res.end(),cmp);


        return res.size()>0?res[0]:"";
        //return res[0];

    }
};
// @lc code=end

