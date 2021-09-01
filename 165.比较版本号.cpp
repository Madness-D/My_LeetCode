/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l1=0,l2=0;
        int len1=version1.size(),len2=version2.size();
        ////通过54/81 想得too simple了
        // while(l1<len1 || l2<len2){
        //     if(version1[l1]=='0'||version1[l1]=='.') l1++;
        //     if(version2[l2]=='0'||version2[l2]=='.') l2++;
        //     if(version1[l1]==version2[l2]){l1++;l2++;}
        //     else if(version1[l1]<version2[l2]) return -1;
        //     else if(version1[l1]>version2[l2]) return 1;
        // }

        //将string转化为整数进行比较
        while(l1<len1 ||l2<len2){
            int x=0,y=0;
            //version1
            for(;l1<len1 &&version1[l1]!='.';++l1){
                x=x*10+version1[l1]-'0';
            }
            ++l1;//跳过'.'
            for(;l2<len2 && version2[l2]!='.';++l2){
                y=y*10+version2[l2]-'0';
            }
            ++l2;
            if(x!=y) return x>y?1:-1;
        }

        return 0;
    }
};
// @lc code=end

