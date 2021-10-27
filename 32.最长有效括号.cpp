/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        // //下面的方法错误，没注意到题目要求的必须连续,too naive
        // stack<char> st;
        // int res=0;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='('){
        //         st.push(s[i]);
        //     }else{
        //         if(st.empty()) continue;
        //         else{ res+=2;st.pop();}
        //     }
        // }
        // return res;

        //思考错误
        //思考, 遇到(,如果栈为空,则入栈,非空则说明
        //遇到),如果非空,则说明没有匹配的,跳过, 重置;否则合法的长度+2,并将栈中的弹出

/*
        官方题解的方法,栈
        始终保持栈底元素为已遍历元素中,最后一个没有被匹配的右括号的下标
        栈里的其他元素维护左括号的下标
            对于遇到的(,将其下标入栈
            遇到), 弹出栈顶元素,来匹配
                如果栈为空, 说明无法匹配,将其下标放入栈,作为`最后一个没有被匹配的右括号的下标`
                如果非空,该右括号下标-栈顶元素(此时应该就一个元素,因此也是栈底元素)的下标,即为以此)为终点的有效子串的长度
*/
        int res=0;
        stack<int> st;
        st.push(-1);//最后一个未被匹配的右括号下标的初始值,-1
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){st.push(i);}
                else{
                    res=max(res,i-st.top());
                }
            }
        }
        return res;
    }
};
// @lc code=end

