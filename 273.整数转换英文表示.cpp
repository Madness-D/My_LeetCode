/*
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
/*
    vector<string> Str1={"","One","Twe","Three","Four","Five","Six","Seven","Eight","Nine"};

    vector<string> Str2 = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

    vector<string> Str3 = {"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};

    string xxxToWords(int xxx){//将三位的转化为字符串
        string res;
        if(xxx/100){
            res+=Str1[xxx/100];
            res+=" Hundred";
        }
        xxx%=100;//取后两位
        res+=" ";
        if(xxx/10>1){
            res+=Str2[xxx/10];
            res+=" ";
        }else if(xxx/10==1){

        }

        return res;
    }
    string numberToWords(int num) {
        //提示：从后向前，三位划分为一个小节，
        //thousand，million，billion

        vector<int>  k3;// 存储划分结果
        while(num){
            k3.push_back(num%1000);
            num/=1000;
        }


    }

    */


    vector<string> singles = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands = {"", "Thousand", "Million", "Billion"};
    
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        string sb;
        for (int i = 3, unit = 1000000000; i >= 0; i--, unit /= 1000) {
            int curNum = num / unit;
            if (curNum != 0) {
                num -= curNum * unit;
                sb = sb + toEnglish(curNum) + thousands[i] + " ";
            }
        }
        while (sb.back() == ' ') {
            sb.pop_back();
        }
        return sb;
    }

    string toEnglish(int num) {
        string curr;
        int hundred = num / 100;
        num %= 100;
        if (hundred != 0) {
            curr = curr + singles[hundred] + " Hundred ";
        }
        int ten = num / 10;
        if (ten >= 2) {
            curr = curr + tens[ten] + " ";
            num %= 10;
        }
        if (num > 0 && num < 10) {
            curr = curr + singles[num] + " ";
        } else if (num >= 10) {
            curr = curr + teens[num - 10] + " ";
        }
        return curr;
    }

};
// @lc code=end

