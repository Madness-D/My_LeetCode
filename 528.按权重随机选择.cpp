/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */

// @lc code=start
//https://leetcode-cn.com/problems/random-pick-with-weight/solution/wei-rao-li-lun-ke-neng-shi-gong-cheng-zh-fh0r/
class Solution {
public:
    int range=0;
    vector<int> weights;

    Solution(vector<int>& w) {
        for(int i=0;i<w.size();i++){
            range+=w[i];
            weights.push_back(range);
            //range+=w[i];
           }
    }
    
    int pickIndex() {
        // int rnd = rand() % range;
        // int i = 0;

        // for (i = 1; i < weights.size(); i++) {
        //     if (rnd < weights[i]) {
        //         break;
        //     }
        // }

        // return i-1;

        int rnd = rand() % range;

        int left = 0;
        int right = weights.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (rnd < weights[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;

    }
};


// class Solution {
// private:
//     mt19937 gen;
//     uniform_int_distribution<int> dis;
//     vector<int> pre;

// public:
//     Solution(vector<int>& w): gen(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0)) {
//         partial_sum(w.begin(), w.end(), back_inserter(pre));
//     }
    
//     int pickIndex() {
//         int x = dis(gen);
//         return lower_bound(pre.begin(), pre.end(), x) - pre.begin();
//     }
// };

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

