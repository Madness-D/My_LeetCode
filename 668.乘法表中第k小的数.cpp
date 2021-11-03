/*
 * @lc app=leetcode.cn id=668 lang=cpp
 *
 * [668] 乘法表中第k小的数
 */

// @lc code=start
class Solution {
public:
    //参考378 有序矩阵, 但是数据量更大了
    //二分法,二分查找. 关键是边界值的选择
    //第k小的数x,换种说法,<=x的数有>=k个(可能有多个x捏)
    //enough函数,返回x是否足够大以成为k_th值

    //一个问题：会不会找到一个不存在于这个表里的数
    //解答：https://leetcode-cn.com/problems/kth-smallest-number-in-multiplication-table/solution/guan-fang-ti-jie-yu-zi-ji-de-yi-wen-java-nxu8/

    bool  enough(int x,int m,int n,int k){
        int count=0;
        for(int i=1;i<=m;i++){//如何统计,<=x的元素个数捏?
        //每一行的数据是有序的,是i*[1、2、3...], 其中<=x的是min(x/i,n)
            int add=min(x/i,n); 
            if(add==0) break;//说明第i行及之后的都>x 了，不用再统计了
            count+=add;
        }
        return count>=k;
    }

    int findKthNumber(int m, int n, int k) {
        int left=1,right=m*n;
        while(left<right){
            int mid=left+(right-left)/2;//防止溢出
            if(enough(mid,m,n,k)){//如果enough,搜索左区间
                right=mid;
            }else{
                left=mid+1;
            }
        }

    return left;
    }
};
// @lc code=end

