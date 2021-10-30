/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // //但是捏, 空间复杂度不是常数级的,set最多存n/2个元素
        // unordered_set<int> us;
        // for(int num:nums){
        //     if(us.count(num)){
        //         us.erase(num);
        //     }else{
        //         us.insert(num);
        //     }
        // }
        // vector<int> res;
        // for(int num:us){
        //     res.push_back(num);
        // }
        // return res;


        //异或
        //1、一个数和自身异或为0
        //2、一个数和0异或，为自己本身  
            
        //所有元素进行异或,最后的结果是A^B
        //关键是如何从异或的结果r里面把A和B分离出来?
        //A^B里面是1的位,A和B是相反的
        int xorsum = 0; 
        for (int num: nums) 
            xorsum ^= num;
        // 防止溢出;  x&-x,取二进制中最低位的1,假设为第k位
        int lsb = (xorsum == INT_MIN ? xorsum : xorsum & (-xorsum));
        int type1 = 0, type2 = 0;
        //对 numsnums 进行遍历，对第k位分别为0和1的元素分别求异或和（两答案必然会被分到不同的组），而其他的元素异或之后就0了,异或后的分别就是答案。
        for (int num: nums) {
            if (num & lsb) {
                type1 ^= num;
            }
            else {
                type2 ^= num;
            }
        }
        return {type1, type2};

    }
};
// @lc code=end

