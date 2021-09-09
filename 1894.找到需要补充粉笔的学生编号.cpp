/*
 * @lc app=leetcode.cn id=1894 lang=cpp
 *
 * [1894] 找到需要补充粉笔的学生编号
 */

// @lc code=start
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {

        long long sum=0;//int会溢出
        for(int i=0;i<chalk.size();i++){
            sum+=chalk[i];
        }
        k%=sum;
        for(int i=0;i<chalk.size();i++){
            ////下面的写法倒数第二个用例未通过
            k-=chalk[i];
            //if(k<=0){//去掉等号可以通过
            if(k<0){
                return i;
            }

            // if(chalk[i]>k){return i;}
            // k-=chalk[i];
        }

        return 0;

    }
};
// @lc code=end

