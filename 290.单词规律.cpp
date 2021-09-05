/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // //利用unordered_map，遍历字符串，存储
        // //使用另一个unordered_map，遍历pattern，存储
        // //先比较两个哈希表的size，不一样的话一定为false
        // //两个迭代器，遍历比较哈希表的it->second
        // //不对，不应该直接用unordered_map,如abba,aabb最后存的都一样，没有位置信息
        // //使用两个数组压缩，如abba存为121，aaaa为4?
        // //但这个方法也不太对，如dog cat cat fish也表示成121了
        // //gg，不会了
        // vector<int> v1,v2;
        // v1.push_back(1);
        // for(int i=1;i<pattern.size();++i){
        //     if(pattern[i]==pattern[i-1]){
        //         v1.back()++;
        //     }else{
        //         v1.push_back(1);
        //     }
        // }

        // v2.push_back(1);
        // int l=0,r=0;
        // string prestr,currstr;
        // while (r < s.size() && s[r] != ' ') r++;
        // prestr=s.substr(l,r-l);
        // r+=2;l=r;
        // while(r<s.size()){
        //     while (r < s.size() && s[r] != ' ') r++;
        //     currstr=s.substr(l,r-l);
        //     if(currstr==prestr){
        //         v2.back()++;
        //         r+=2;l=r;
        //         prestr=currstr;
        //     }else{
        //         v2.push_back(1);
        //         r+=2;l=r;
        //         prestr=currstr;
        //     }
        // }

        // if(v1.size()!=v2.size()) return false;
        // else{
        //     for(int i=0;i<v1.size();i++){
        //         if(v1[i]!=v2[i]) return false;
        //     }
        // }
        // return true;

        //本质是判断pattern里的字符和s里的字符串，是不是双射关系，即，恰好一一对应
        //
        unordered_map<string , char> str2ch;
        unordered_map<char,string> ch2str;
        int len=s.length();
        int i=0;
        for(auto ch:pattern){
            if(i>=len){
                return false;
            }
            int j=i;
            while(j<len && s[j]!=' ') j++;
            //整成const & 节省空间
            const string &tmp=s.substr(i,j-i);//截取的字符串，单词
            //判断双射关系,如果前面已经出现过这个单词或字符，且不符合双射则false
            if(str2ch.count(tmp)&&str2ch[tmp]!=ch){
                return false;
            }
            if(ch2str.count(ch)&&ch2str[ch]!=tmp){
                return false;
            }
            //没出现则添加，出现且符合双射的话，也没有影响
            str2ch[tmp]=ch;
            ch2str[ch]=tmp;
            i=j+1;

        }

        //正常循环的话，应该是true？
        //如果直接return true, 则aaa 和“aa aa aa aa” 答案错误
        return i>=len;
        //return true;
    }
};
// @lc code=end

