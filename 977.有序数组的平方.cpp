/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        /*  sort函数
        vector<int> res;
        int len=nums.size();
        res.resize(len);
        for(int i=0;i<len;i++){
            res[i]=nums[i]*nums[i];
        }
        sort(res.begin(),res.end());
        return res;
        */
       
       /*   双指针，分别从尾部和头部移动*/
        vector<int> res;
        int len=nums.size();
        res.resize(len);
        int left=0,right=len-1;
        int pos=right;
        while(left<=right){//要有等号
            int n1=nums[left]*nums[left];
            int n2=nums[right]*nums[right];
            if(n1<=n2){
                res[pos]=n2;
                right--;
            }else{
                res[pos]=n1;
                left++;
            }
            pos--;
        }
        return res;

    }
};
// @lc code=end

