/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
//map会自动按key值排序，不行
//unordered_map 行
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        // for(int i=0;i<s.length();i++){
        //     mp[s[i]]++;
        // }
       
        // for(int i=0;i<s.length();i++){
        //     if(mp[s[i]]==1) return i;
        // }
        // return -1;

        //应该使用迭代器
        //但是unmap是逆序存放的，且其迭代器是前向迭代器，不能逆向迭代
        // unordered_map<char,int>::iterator iter=mp.end();
        // iter--;
        // for(;iter!=mp.begin();iter--){
        //     if(iter->second==1){
        //         return s.find(iter->first);break;
        //     }
        // }

        for(int i=0;i<s.length();i++){
            if(mp.count(s[i])){
                mp[s[i]]=-1;
            }else{
                mp[s[i]]=i;
            }
        }

        unordered_map<char,int>::iterator iter=mp.begin();
        int res=s.length();
        for(;iter!=mp.end();iter++){
            if(iter->second!=-1 && iter->second<res){
                res=iter->second;
            }
        }
        if(res==s.length()){return -1;}
        return res;
 
    }
};
// @lc code=end

