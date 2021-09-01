/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    void reversepart(string &s,int left,int right){
        while(left<right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
    string reverseStr(string s, int k) {
        int flag=1;//标记是否是第奇数个k子串
        int left=0,right=0,len=s.size();
        if(k>=len){
            reversepart(s,0,len-1);
        }else{
            right=k-1;
        while(right<=len-1 && left<right){
            if(flag%2 ==1){
                reversepart(s,left,right);
                }

            // if(left+k<len-1){
            //     left+=k;
            // }else{
            //     left=len-1;
            // }
            left+=k;
            if(right+k<len){
                right=right+k;
            }else{
                right=len-1;
            }
            flag++;
        }
        }
        return s;
    }
};
// @lc code=end

