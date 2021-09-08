/*
 * @lc app=leetcode.cn id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start

typedef pair<int,int> pii;//把成本和利润绑定
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //贪心算法
        //如果不限制次数，按照需要的资本大小进行排序，依次购入项目i，则资本增值profit[i],直到手里的资本无法启动新项目
        //如果初始资本w>=max(capital)，直接返回利润里的k个最大的就可以
        //每次选择需要投资成本<= 手中资本的项目中利润最大的，然后更新手里的资本，重复选择
        //利用一个大根堆来维护存储所有能投资的项目的利润
        int len=profits.size();
        int curr=0;
        priority_queue<int,vector<int>,less<int>> pq;//less,大顶堆
        vector<pii> arr;//
        for(int i=0;i<len;i++){
            arr.push_back({capital[i],profits[i]});
        }
        sort(arr.begin(),arr.end());// sort by capital
        for(int i=0;i<k;++i){
            while(curr<len && arr[curr].first<=w){//将成本<=w的插入队列
                pq.push(arr[curr].second);
                curr++;
            }
            if(!pq.empty()){
                w+=pq.top();
                pq.pop();
            }else{break;}
        }
        return w;
    }
};
// @lc code=end

