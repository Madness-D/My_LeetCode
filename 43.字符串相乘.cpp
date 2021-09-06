/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        //num1和num2 长度分别为m和n，则m*n的长度为m+n-1 或 m+n
        //创建长度为m+n的数组res来存储结果
        //num1[i]*num2[j] 的结果位于　res[i+j+1],>10则进位

        if(num1=="0"||num2=="0")
            return "0";

        int m=num1.size(),n=num2.size();
        vector<int> ansArr(m+n);
        for (int i = m - 1; i >= 0; i--) {
            int x = num1.at(i) - '0';
            for (int j = n - 1; j >= 0; j--) {
                int y = num2.at(j) - '0';
                ansArr[i + j + 1] += x * y;
            }
        }
        //这时存储的可能有>10的元素
        for (int i = m + n - 1; i > 0; i--) {
            ansArr[i - 1] += ansArr[i] / 10;
            ansArr[i] %= 10;
        }
        int index = ansArr[0] == 0 ? 1 : 0;
        //将数组转化为字符串
        string ans;
        while (index < m + n) {
            ans.push_back(ansArr[index]);
            index++;
        }
        for (auto &c: ans) {
            c += '0';
        }

        return ans;

    }
};
// @lc code=end

