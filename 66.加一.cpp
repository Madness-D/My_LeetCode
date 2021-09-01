/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size();
        // digits[len-1]++;
        // return digits;
        int carry = 0;
        digits[len-1] += 1;
        for(int i = len-1;i > 0;--i){
            digits[i] += carry;
            carry = digits[i]/10;
            digits[i] %= 10;
            
        }
        digits[0] += carry;
        if(digits[0] >= 10){
            digits[0] = 0;
            digits.insert(digits.begin(),1);
        }  
        return digits;

    }
};
// @lc code=end

