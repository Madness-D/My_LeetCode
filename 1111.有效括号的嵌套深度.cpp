/*
 * @lc app=leetcode.cn id=1111 lang=cpp
 *
 * [1111] 有效括号的嵌套深度
 */

// @lc code=start
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        // //对于在原串中的层数,将奇数层的分给A,偶数层的分给B
        // //对于层数,如果遇到(,则层数++,再分配
        // //遇到), 先分配, 再层数--
        // int d=0;//层数
        // vector<int> res;
        // for(char ch:seq){
        //     if(ch=='('){
        //         ++d;
        //         res.push_back(d%2);
        //     }else{
        //         res.push_back(d%2);
        //         --d;
        //     }
        // }
        // return res;

        //找规律,左括号 ( 的下标编号与嵌套深度的奇偶性相反,
        //右括号 ) 的下标编号与嵌套深度的奇偶性相同
        vector<int> res;
        for(int i=0;i<seq.size();i++){
            if(seq[i]=='('){
                res.push_back(i%2);
            }else{
                res.push_back((i+1)%2);
            }
        }
        return res;
    }
};
// @lc code=end

