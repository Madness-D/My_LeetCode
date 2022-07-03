/* ************************************************************************
> File Name:		01背包.cpp
> Author:		bwding
> Mail:		dingbuowen@outlook.com
> Created Time:		2022-07-03 14:40:58
> Link:		https://www.nowcoder.com/questionTerminal/708f0442863a46279cce582c4f508658
> Description:		
*************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int cap=0,n=0;
    cin>>cap>>n;
    vector<int> weight(n,0);
    vector<int> value(n,0);

    for(int i=0;i<n;i++){
        cin>>weight[i]>>value[i];
    }


/*  二维的dp
    //dp[i][j] 0-i物品，容量为j
    vector<vector<int>> dp(n,vector<int>(cap+1,0));
    //初始化
    //for(int i=0;i<n;i++) dp[i][0]=0;
    //for(int j=0;j<weight[0];j++) dp[0][j]=0;
    for(int j=weight[0];j<=cap;j++) dp[0][j]=value[0];

    for(int i=1;i<n;i++){
        for(int j=1;j<=cap;j++){
            if(j>=weight[i]){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n-1][cap]<<endl;
*/

    //一维，滚动数组. 观察原来的递推公式，每一层可以重复利用上一层
    //重新定义一维dp： dp[j]表示容量为j的背包所背的最大价值
    //递推公式：  dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
    //仍然需要两次遍历，物品、容量；且容量需要逆序遍历，且必须先物品再容量
    vector<int> dp(cap+1,0);
    for(int i=0;i<n;i++){
        for(int j=cap;j>=weight[i];j--){
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    cout<<dp[cap]<<endl;


    return 0;

}