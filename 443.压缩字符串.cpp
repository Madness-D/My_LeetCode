/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

// @lc code=start
class Solution {
public:
    int compress(vector<char>& chars) {
        int l=0,r=0;
        int len=chars.size();
        vector<char> res;
        while(r!=len){
            while(chars[r]==chars[l]){r++;if(r>=len){break;}}
            res.push_back(chars[l]);
            int temp=r-l;
            if(temp>1){
                //这里是倒序插入的，插入后reverse一下
                int leftt=res.size();
                //int rightt=leftt+temp;
            while(temp){
                res.push_back(temp%10+'0');
                temp=temp/10;
            }
            //int rightt=res.size();
            //reverse(&res[leftt],&res[rightt]);
            reverse(res.begin()+leftt,res.end());//
            }
            l=r;
        }
    chars=res;
    return res.size();
    }
};
// @lc code=end

