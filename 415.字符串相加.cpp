/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {

        //my_code，双指针，遍历，相加，>10则进位
        //主要是string的insert函数   https://www.cnblogs.com/meihao1203/p/9670680.html
        //插入单个字符时需指明插入的个数，即(pos,counter,ch)
        //很ugly，不够优雅
        int p1=num1.size()-1,p2=num2.size()-1;
        string s;
        int sum=0;
        // while(p1>=0 && p2>=0){
        //     sum+=num1[p1]-'0'+num2[p2]-'0';
        //     if(sum<10){s.insert(0,1,sum+'0');sum=0;p1--;p2--;}
        //     else {s.insert(0,1,sum-10+'0');sum=1;p1--;p2--;}
        // }
        // while(p1>=0){
        //     sum+=num1[p1]-'0';
        //     if(sum<10){s.insert(0,1,sum+'0');sum=0;p1--;}
        //     else{s.insert(0,1,sum-10+'0');sum=1;p1--;}
        // }
        // while(p2>=0){
        //     sum+=num2[p2]-'0';
        //     if(sum<10){s.insert(0,1,sum+'0');sum=0;p2--;}
        //     else{s.insert(0,1,sum-10+'0');sum=1;p2--;}
        // }
        // if(sum>0){//最后进位，否则如“1”、“9”，字符串长度相等，且需要进位，会报错
        //     s.insert(0,1,'1');
        // }
        // return s;

        //官方题解，思路是一样的
        //注意循环条件
        while(p1>=0 || p2>=0 ||sum!=0){
            int x=p1>=0?num1[p1]-'0':0;
            int y=p2>=0?num2[p2]-'0':0;
            sum+=x+y;
            s.insert(0,1,'0'+sum%10);
            sum/=10;
            p1--;
            p2--;
        }

        return s;



    }
};
// @lc code=end

