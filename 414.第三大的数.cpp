/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // //有序集合
        // set<int> st;
        // for(int num:nums){
        //     st.insert(num);
        //     if(st.size()>3){
        //         st.erase(st.begin());
        //     }
        // }
        // // if(st.size()==3) return *st.begin();
        // // //反向迭代器，返回最后一个元素
        // // else return *st.rbegin();
        // return st.size()<3?*st.rbegin():*st.begin();
        

        //第三大的数，比较小，可以使用三个变量存储
        //-2147483648,边界值，需要用long存储
        long a=LONG_MIN,b=LONG_MIN,c=LONG_MIN;
        for(int num:nums){
            if(num>a){
                c=b;
                b=a;
                a=num;
            }else if( num<a && num>b){
                c=b;
                b=num;
            }else if(num<b && num>c){
                c=num;
            }
        }

        return c==LONG_MIN?a:c;

    }
};
// @lc code=end

