/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution {
public:
    string fun(int i){
        if(i%3==0 && i%5==0){
            return "FizzBuzz";
        }else if(i%3==0){
            return "Fizz";
        }else if(i%5==0){
            return "Buzz";
        }else{
            return to_string(i);
        }
    }
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i=1;i<=n;i++){
            res.push_back(fun(i));
        }
        return res;
    }
};
// @lc code=end

