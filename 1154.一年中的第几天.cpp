/*
 * @lc app=leetcode.cn id=1154 lang=cpp
 *
 * [1154] 一年中的第几天
 */

// @lc code=start
class Solution {
    bool isLeap(int year){
        return (year%4==0 && year%100!=0)|| (year%400==0);
    }
public:
    int dayOfYear(string date) {
        int year=0,month=0,day=0,res=0;
        string ye=date.substr(0,4),mo=date.substr(5,2),da=date.substr(8,2);
        for(char ch:ye){  year=year*10+(ch-'0');}
        for(char ch:mo){month=month*10+(ch-'0');}
        for(char ch:da){day=day*10+(ch-'0');}
        int amonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(isLeap(year)){amonth[1]++;}
        for(int i=0;i<month-1;i++){
            res+=amonth[i];
        }
        res+=day;
        return res;
    }
};
// @lc code=end

