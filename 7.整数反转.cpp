/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
//判断溢出
class Solution {
public:
    int reverse(int x) {
        // bool ispositive=true;
        // if(x<0){ispositive=false;x=-x;}
        vector<int> temp;
        while(x) {
            temp.push_back(x%10);
            x/=10;
        }
        //reverse(temp.begin(),temp.end());
        int res=0;
        for(int i=0;i<temp.size();i++){
            if(res>0 && res>2147483647/10){
                return 0;
            }else if(res<0 && res<-2147483648/10){
                return 0;
            }
            else{
            res*=10;
            res+=temp[i];}

        }
        // if(ispositive) return res;
        // else if(res==2147483648){ return 0;}
        // else return -res;
        return res;
    }
};
// @lc code=end

