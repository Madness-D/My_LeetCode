/*
 * @lc app=leetcode.cn id=335 lang=cpp
 *
 * [335] 路径交叉
 */

// @lc code=start
class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        // //也没说只走一圈啊,想啥捏
        // return (distance[0]>=distance[2])&&(distance[1]<=distance[3]);
        int  up=0,down=0,left=0,right=0;
        for(int i=0;i<distance.size();i++){
            if(i%4==0) up+=distance[i];
            else if(i%4==1) left+=distance[i];
            else if(i%4==2) down+=distance[i];
            else if(i%4==3) right+=distance[i];
        }
        return (up>=down && left<=right);
    }
};
// @lc code=end

