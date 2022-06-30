/* ************************************************************************
> File Name:		406根据身高重建队列.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-27 15:30:27
> Link:		https://leetcode.cn/problems/queue-reconstruction-by-height/
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

bool mycmp(vector<int> &v1,vector<int> &v2){
    return v1[0]<v2[0] || (v1[0]==v2[0] && v1[1]> v2[1]);
}
class Solution {
public:
     vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        //vector<vector<int>> ans(n);
          vector<vector<int>> ans;

        ////从低到高拍，前面的矮的不影响，只需要确保后面的比自己高的有k个会站自己前面就行
        ////即，需要前面有k个空位
        //sort(people.begin(),people.end(),mycmp);
        //lambda表达式捏
        // sort(people.begin(),people.end(),[](const vector<int> &v1, const vector<int> &v2){
        //     return v1[0]<v2[0] || (v1[0]==v2[0] && v1[1]> v2[1]);});
        // //保证前面有k个空位，即插入第k+1个空位即可
        // for(const auto & person:people){
        //     int k=person[1]+1;
        //     for(int i=0;i<n;i++){
        //         if(ans[i].empty()){
        //             k--;
        //             if(!k){
        //                 ans[i]=person;
        //                 break;
        //             }
        //         }
        //     }
        // }

//
        sort(people.begin(),people.end(),[](const vector<int> &v1, const vector<int> &v2){
            return v1[0]>v2[0] || (v1[0]==v2[0] && v1[1] < v2[1]);});
        //这个时候，是从高向低遍历，只要前面有k个元素即可，则用insert
        for(const auto &person:people){
            ans.insert(ans.begin()+person[1],person);
        }


        return ans;
    }
};