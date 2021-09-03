/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // //两个数组，分别存储前缀元素的积，后缀元素的积
        // //三次遍历，应该时间复杂度为O(3n)?
        // //空间复杂度也是O(n)
        // int len=nums.size();
        // vector<int> q(len);
        // vector<int> h(len);
        // vector<int> res(len);
        // int temp=1;
        // q[0]=1;
        // for(int i=1;i<len;++i){
        //     temp*=nums[i-1];
        //     q[i]=temp;
        // }
        // h[len-1]=1;
        // temp=1;
        // for(int i=len-2;i>=0;--i){
        //     temp*=nums[i+1];
        //     h[i]=temp;
        // }
        // for(int i=0;i<len;i++){
        //     res[i]=q[i]*h[i];
        // }
        // return res;

        // //上面用到了三个数组，优化成1个
        // int len=nums.size();
        // vector<int> res(len);
        // int temp=1;
        // res[0]=1;
        // for(int i=1;i<len;++i){
        //     temp*=nums[i-1];
        //     res[i]=temp;
        // }//此时res内存的前缀积
        // //再逆序遍历一次，乘上后缀积
        // temp=1;
        // for(int i=len-2;i>=0;--i){
        //     temp*=nums[i+1];
        //     res[i]*=temp;
        // }
        // return res;

        //再优化，只遍历一次
        int len=nums.size();
        vector<int> res(len,1);//后面有res[i]*=的操作，需要初始化为1
        int l=1,r=1;       
        for(int i=0;i<len;++i){
            res[i]*=l;
            l*=nums[i];

            res[len-1-i]*=r;
            r*=nums[len-1-i];
        }
        return res;



    }
};
// @lc code=end

