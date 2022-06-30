/* ************************************************************************
> File Name:		452引爆气球.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-27 18:21:07
> Link:		https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
    sort(points.begin(),points.end(),[](const vector<int>& v1,const vector<int> &v2){
        return v1[0]<v2[0]||(v1[0]==v2[0]&&v1[1]<v2[1]);});


    int cnt=1; 
    //重叠气球的右边界最小值
    for(int i=1;i<points.size();i++){
        if(points[i][0]>points[i-1][1]) cnt++;
        //注意下面的是min
        else points[i][1]=min(points[i][1],points[i-1][1]); 
    }
    return cnt;
    }
};