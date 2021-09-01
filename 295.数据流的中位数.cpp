/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
//有序列表
//数组，超时了
//数组，改进插入顺序，死于18/21
//multiset
//两个优先，实现双堆，两个堆的对顶元素求均值
class MedianFinder {
public:
    /** initialize your data structure here. */
    //vector<int> nums;
    priority_queue<int> small;//大根堆，存左半部分
    priority_queue<int, vector<int>, greater<int> > big;
    int n;
    MedianFinder() {
            n=0;
    }
    
    void addNum(int num) {
        // nums.push_back(num);
        // // sort(nums.begin(),nums.end());
        // int tmp=num;
        // int i=nums.size()-2;
        // while(i>=0&&nums[i]>tmp){
        //     nums[i+1]=nums[i];
        //     i--;
        // }
        // nums[i+1]=tmp;

        if(small.empty()){small.push(num);n++;return;}
        if(num<=small.top()){small.push(num);}
        else{big.push(num);}
        if(small.size()>big.size()+1){big.push(small.top());small.pop();}
        if(small.size()+1<big.size()){small.push(big.top());big.pop();}
        n++;
        
    }
    
    double findMedian() {
        // int len=nums.size();
        // if(len%2!=0){//奇数
        //     return nums[len/2];
        // }else{
        //     return (double)(nums[len/2]+nums[len/2-1])/2;
        // }


         if(n%2){
            if(small.size()>big.size())return small.top();
            else return big.top();
        }
        else return ((long long)(small.top())+big.top())*0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

