/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        //本来想的双指针，但是看了提示，直接从末尾遍历
        //对于空格，删去
        int index=s.size()-1;
        while(s[index]==' '){
            index--;
        }
        int res=0;
        //注意&&的两个条件的顺序
        while(index>=0 &&s[index]!=' ' ){
            index--;
            res++;
        }
        return res;

    }
};
// @lc code=end

