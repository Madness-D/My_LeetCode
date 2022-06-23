/* ************************************************************************
> File Name:		860柠檬水找零.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-22 11:43:42
> Link:		https://leetcode.cn/problems/lemonade-change/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int money[3]={0};//0,1,2分别对应5，10，20美元的数量
        for(auto &it:bills){
            if(it==5){//5
                money[0]++;
            }else if(it==10){//10
                if(money[0]<1) return false;
                money[0]--;
                money[1]++;
            }else{//20
                if(money[1]>0 && money[0]>0){
                    money[1]--;
                    money[0]--;
                    money[2]++;
                }else if(money[0]>2){
                    money[0]-=3;
                    money[2]++;
                }else{
                    return false;
                }
            }
        }

        return true;
    }
};