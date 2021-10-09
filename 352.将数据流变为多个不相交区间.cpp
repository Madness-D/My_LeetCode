/*
 * @lc app=leetcode.cn id=352 lang=cpp
 *
 * [352] 将数据流变为多个不相交区间
 */

// @lc code=start
//https://leetcode-cn.com/problems/data-stream-as-disjoint-intervals/solution/suan-fa-xiao-ai-chao-ji-xiang-xi-de-ti-j-u44x/
class SummaryRanges {
public:
    vector<vector<int>> v;
    unordered_set<int> s;
    SummaryRanges() {

    }
    
int binary_search(int target, int pos) {
        int l = 0, r = v.size() - 1, ans;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(v[mid][pos] == target) {
                ans = mid;
                break;
            } else if(v[mid][pos] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    
    void addNum(int val) {
        if(s.count(val)) return;
        // 未出现过
        s.insert(val);
        if(s.count(val + 1) && s.count(val - 1)) {
            // 需要合并 [..., val - 1] 和 [val + 1, ...] 两个区间
            int left = binary_search(val - 1, 1);
            int right = binary_search(val + 1, 0);
            // printf("val = %d, left = %d, right = %d\n", val, left, right);
            v[left][1] = v[right][1];
            v.erase(v.begin() + right);
        } else if(s.count(val + 1)) {
            // val + 1 出现过，说明有以 val + 1 为左端点的区间
            // 二分查找该区间
            int ans = binary_search(val + 1, 0);
            // 找到的区间形如 [val + 1, ...]，需要修改为 [val, ...]
            v[ans][0] = val;
        } else if(s.count(val - 1)) {
            // 有以 val - 1 为右端点的区间
            int ans = binary_search(val - 1, 1);
            // 找到的区间形如 [..., val - 1]，需要修改为 [..., val]
            v[ans][1] = val;
        } else {
            // 左右都未出现，val 形成一个独立区间
            v.push_back(vector<int>{val, val});
        }

        // 保证数组有序性
        sort(v.begin(), v.end());
    }
    
    vector<vector<int>> getIntervals() {
        return v;
    }

};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end

