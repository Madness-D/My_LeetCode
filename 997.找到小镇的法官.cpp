/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // //来一个数组，记录是否相信其他人
        // set<int> st;
        // for(int i=1;i<=n;i++){
        //     st.insert(i);
        // }
        // for(int i=0;i<trust.size();i++){
        //     st.erase(trust[i][0]);//把相信别人的人删除
        // }//这是set里是可能的法官
        // if(st.size()==0) return -1;//如测试用例3，没有不相信任何人的人，就说明没有法官
        // //未完成

        //出度，入度
        //法官：出度为0，入度为n-1
        vector<int> outde(n+1,0);
        vector<int> inde(n+1,0);

        for(int i=0;i<trust.size();i++){
            outde[trust[i][0]]++;
            inde[trust[i][1]]++;
        }

        for(int i=1;i<=n;i++){
            if(outde[i]==0 && inde[i]==n-1) return i;
        }
        return -1;


    }
};
// @lc code=end

