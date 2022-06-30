/* ************************************************************************
> File Name:		56合并区间.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-27 18:47:22
> Link:		https://leetcode.cn/problems/merge-intervals/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int> &v1,const vector<int> &v2){
            return v1[0]<v2[0]||(v1[0]==v2[0]&&v1[1]<v2[1]) ;} );
        int prel=intervals[0][0],prer=intervals[0][1];
        vector<vector<int>> ans;
        for(int i=1;i<intervals.size();i++){
            if(prer<intervals[i][0]){
                ans.push_back({prel,prer});
                prel=intervals[i][0];
                prer=intervals[i][1];
            }else{
                prel=min(prel,intervals[i][0]);
                prer=max(prer,intervals[i][1]);
            }
        }
        ans.push_back({prel,prer});
        return ans;
    }
};