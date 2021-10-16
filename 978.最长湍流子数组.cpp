/*
 * @lc app=leetcode.cn id=978 lang=cpp
 *
 * [978] 最长湍流子数组
 */

// @lc code=start
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        //滑动窗口
        if(arr.size()==1) return 1;
        if(arr.size()==2) {
            if(arr[0]!=arr[1]) return 2;
            else return 1;
        }
        int l=0,r=0;
        int res=1;
        // for(int i=2;i<arr.size();i++){
        //     //如果符合标准，就r++，更新res
        //     if((arr[i]-arr[i-1])*(arr[i-1]-arr[i-2])<0){
        //         r++;
        //         res=res>(r-l+1)?res:r-l+1;
        //     }else{
        //         l=i-1;
        //         r=i;
        //     }
        // }
        while(r<arr.size()-1){
            if(l==r){
                if(arr[l]==arr[l+1]){//应对连续相等的情况
                    l++;
                }
                r++;
            }else{
                //这里用了乘法，会溢出
                if((long)(arr[r]-arr[r-1])*(arr[r+1]-arr[r])<0){
                    r++;
                }else{
                    l=r;
                }
            }
            res=res>(r-l+1)?res:r-l+1;
        }
        return res;

    }
};
// @lc code=end

