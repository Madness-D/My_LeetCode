/* ************************************************************************
> File Name:		455分发饼干.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-06-21 20:57:51
> Link:		
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int p1=0,p2=0;
        while(p1<g.size() && p2<s.size()){
            if(s[p2]>=g[p1]){ // 能够满足
                p1++;
                p2++;
            }else{
                p2++;
            }
        }
        return p1;
    }
};