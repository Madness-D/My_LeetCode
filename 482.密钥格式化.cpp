/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */

// @lc code=start
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string str;
        //去除‘-’
        for(char ch:s){
            if(ch!='-'){
                str+=ch;
            }
        }

        int cnt=str.size();

        //改成大写
        for(char &ch:str){
            if(ch<='z' && ch>='a'){
                ch=ch-'a'+'A';
            }
        }
        
        int group=cnt/k;
        string res;
        //str.insert(cnt%k,1,'-');
        if(cnt%k==0){
            for(int i=0;i<group;i++){
                res+=str.substr(i*k,k);
                if(i<group-1) res+='-';
            }
        }else{
            res+=str.substr(0,cnt%k);
            if(group>0){
                res+='-';
            for(int i=0;i<group;i++){
                res+=str.substr(i*k+cnt%k,k);
                if(i<group-1) res+='-';
                }
            }

        }

        return res;


        // //从尾部向前循环，最后再反转一下
        // string ans;
        // int cnt=0;
        // for(int i=s.size()-1;i>=0;i--){
        //     if(s[i]!='-'){
        //         //小写字母大写
        //         if(s[i]<='z' && s[i]>='a'){
        //             s[i]=s[i]-'a'+'A';
        //         }
        //         ans+=s[i];
        //         cnt++;
        //         if(cnt%k==0){
        //             ans+='-';
        //         }
        //     }
        // }
        // //避免出现，起点出有一个‘-’
        // if(ans.size()>0 && ans.back()=='-'){
        //     ans.pop_back();
        // }

        // reverse(ans.begin(),ans.end());
        // return ans;



    }
};
// @lc code=end

