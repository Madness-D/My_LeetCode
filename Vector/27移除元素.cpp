/* ************************************************************************
> File Name:     27移除元素.cpp
> Author:        bwding
>  mail:         dingbuowen@outlook.com
> Created Time:  Thu 28 Apr 2022 03:12:45 PM CST
> link:          https://leetcode-cn.com/problems/remove-element/
> Description:   给定数组nums中移除等于val的元素，返回移除后的数组长度
                 要求，仅使用额外的O(1)空间
 ************************************************************************/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len=nums.size();
    // 思路1， 双重循环，遇到符合条件的元素，内层循环将其后的所有元素依次前移，覆盖，复杂度n^2
    /*   for(int i=0;i<len;i++){
            if(nums[i]==val){
                for(int j=i+1;j<len;j++){
                    nums[j-1]=nums[j];
                }
                i--;
                len--;
            }
        }
        return len;
    */

    /****************
      * 思路2，双指针，l和r
      * nums[r]==var，即需要覆盖的，则r++，l不动
      * 否则，将r指针的元素覆盖到l，然后l++，r++
      * 
    */
    int l=0,r=0;
    while(r<len){
        if(nums[r]==val) r++;
        else{
            nums[l]=nums[r];
            l++;r++;
        }
    }
    return l;
         
    }
};
