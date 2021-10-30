/*
 * @lc app=leetcode.cn id=1111 lang=cpp
 *
 * [1111] 有效括号的嵌套深度
 */

// @lc code=start
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        //对于在原串中的层数,将奇数层的分给A,偶数层的分给B
        int d=0;//层数
        vector<int> res;
        for(char ch:seq){
            if(ch=='('){
                d++;
                res.push_back(d%2);
            }else{
                res.push_back(d%2);
                d--;
            }
        }
        return res;
    }
};
// @lc code=end

