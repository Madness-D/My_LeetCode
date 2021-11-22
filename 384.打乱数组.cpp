/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start
class Solution {
public:
  vector<int> a, b;
    Solution(vector<int>& nums) {
        a = nums;
        b = nums;//存储初试状态
    }
    
    vector<int> reset() {
      a = b;
      return a;
    }
    
    vector<int> shuffle() {
       for(int i = 1; i < a.size(); i++) {
            int index = rand() % (i + 1);
            if(index != i) {
                swap(a[index],a[i]);
            }
        }
        return a;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

