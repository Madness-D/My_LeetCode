/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
//一个不成熟的想法，将s1中各个char的出现情况存储成一个哈希表，
//题中限制了只有小写字母，可以用数组存
//然后在s2上，遍历各个长度为s1.size()的串
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> s1t(26,0),s2t(26,0);
        for(int i=0;i<s1.size();i++){//存储记录
            s1t[s1[i]-'a']++;
            s2t[s2[i]-'a']++;
        }
        if(s1t==s2t){//vector重载了==，仅限于元素为基本数据类型
            return true;
        }
        int left=1;//
        int le=s1.size();//窗口长度
        while(left<=s2.size()-le){//注意等号
            s2t[s2[left-1]-'a']--;
            s2t[s2[left+le-1]-'a']++;
            if(s1t==s2t){return true;}
            left++;//注意循环变量
        }
        return false;

    }
};
// @lc code=end

