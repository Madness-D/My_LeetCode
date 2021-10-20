/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
 */

// @lc code=start
class Solution {
    //该题是10.16，字节后端训练营入营笔试的第三题
    //思路,先利用一个数组记录各个字母出现的次数，然后将高频的先插入到奇数位，剩下的字母继续插，奇数插满了则插偶数位
    //何时不可行：最高频次大于n/2
public:
    string reorganizeString(string s) {
        //不初始化会出错
        int freq[26]={0};
        int mosFlag=0;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
            if(freq[s[i]-'a']>freq[mosFlag]){
                mosFlag=s[i]-'a';
            }
        }

        if((2*freq[mosFlag]-1)>s.size()) return "";

        string res;
        res.resize(s.size());
        
        int pos=0;
        //存最高频
        while(freq[mosFlag]){
            res[pos]=('a'+mosFlag);
            freq[mosFlag]--;
            pos+=2;
        }
        
        for(int i=0;i<26;i++){
            while(freq[i]){
                if(pos>=s.size()){
                    pos=1;
                    }
                res[pos]=('a'+i);
                freq[i]--;
                pos+=2;
            }
        }
    return res;
    }
};
// @lc code=end

