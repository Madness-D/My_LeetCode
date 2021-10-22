/*
 * @lc app=leetcode.cn id=492 lang=cpp
 *
 * [492] 构造矩形
 */

// @lc code=start
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w=sqrt(area)+1;//+1是和while--配套,不想写forl
        while(w--){
            if(area%w==0)
                return{area/w,w};
        }

    return {};
    }
};
// @lc code=end

