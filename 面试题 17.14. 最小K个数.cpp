class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        // //排序，输出
        // sort(arr.begin(),arr.end());
        // // vector<int> res(k);
        // // for(int i=0;i<k;i++){
        // //     res[i]=arr[i];
        // // }
        // // return res;
        // arr.resize(k);
        // return arr;

        //最大堆,使用优先队列
        vector<int> res(k,0);
        int n=arr.size();
        if(k==0) return res;
        priority_queue<int> q;
        for(int i=0;i<k;i++){
            q.push(arr[i]);
        }
        for(int i=k;i<n;i++){
            if(q.top()>arr[i]){//大根堆的根，>arr[i]，
                q.pop();
                q.push(arr[i]);                
            }
        }
        for(int i=0;i<k;i++){
            res[i]=q.top();
            q.pop();
        }        
        return res;
    }
};