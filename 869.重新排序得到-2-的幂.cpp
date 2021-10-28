/*
 * @lc app=leetcode.cn id=869 lang=cpp
 *
 * [869] 重新排序得到 2 的幂
 */

// @lc code=start

string countDigits(int n) {
    string cnt(10, 0);
    while (n) {
        ++cnt[n % 10];
        n /= 10;
    }
    return cnt;
}

unordered_set<string> powerOf2Digits;

int init = []() {
    for (int n = 1; n <= 1e9; n <<= 1) {
        powerOf2Digits.insert(countDigits(n));
    }
    return 0;
}();


class Solution {

public:
    bool reorderedPowerOf2(int n) {
        //1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,
        //一个大胆的想法, 记录数字出现次数,进行匹配
        //https://leetcode-cn.com/problems/reordered-power-of-2/comments/89397
        //参考上面这个,直接记录排序的结果
        // unordered_set<string> st={"1","2","4","8","16","23","46","128","256","125","0124","0248","0469","1289","13468","23678","35566","011237","122446","224588","0145678","0122579","0134449","0368888","11266777","23334455","01466788","112234778","234455668","012356789","0112344778"};
        // string s=to_string(n);
        // sort(s.begin(),s.end());
        // if(st.count(s)) return true;
        // else return false;

        return powerOf2Digits.count(countDigits(n));
    


    }
};
// @lc code=end

