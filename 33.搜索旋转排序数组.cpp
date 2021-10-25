/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // //遍历,比较
        // for(int i=0;i<nums.size();i++){
        //     if(target==nums[i])
        //         return i;
        // }
        // return -1;

        //改进,要求复杂度为logn, 应该是二分法,但是如何判断比较?
        //数组已经排序了,只不过在某一点会下降
        //对于元素nums[i], 
            //如果nums[i]>=nums[0],说明旋转的点不在0～i之间,如果nums[0]<=target<=nums[i],则继续搜索0～i
            //如果nums[i]<nums[0],说明[0,i]中包含旋转点,则元素nums[i+1,...end]是已排序的,且元素大小介于nums[i]和nums[0]之间
        //总结:什么时候继续搜索0～i: ①nums[0]<=target<=nums[i]; ②target<=nums[i]<nums[0];③nums[i]<nums[0]<=target
        //三个判断条件:(nums[0] <= target), (target <= nums[i]) and (nums[i] < nums[0])  这三个条件不会同时为真,也不会同时为假,因此需要能够分辨出是只有1个真
        int lo = 0, hi = int(nums.size()) - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            //三个条件取反面
            //异或, 三个条件只有1个为真的时候,执行if语句
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo == hi && nums[lo] == target ? lo : -1;

    }
};
// @lc code=end

