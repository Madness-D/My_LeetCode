/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int alen=a.size(),blen=b.size();
        //
        string res;
        int i=alen-1,j=blen-1;
        int carry=0;
        while(i>=0 || j>=0 || carry){
            if(i>=0){
                carry+=a[i]-'0';
                i--;
            }
            if(j>=0){
                carry+=b[j]-'0';
                j--;
            }
            //注意下面两种增加字符的方法, 第一个是增加到res后面,因此需要reverse一下
            res+=(carry%2==0?'0':'1');
            //res=(carry%2==0?'0':'1')+res;
            carry/=2;
        }
        ////
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

