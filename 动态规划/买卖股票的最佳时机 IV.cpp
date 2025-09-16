/*
188. 买卖股票的最佳时机 IV
https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 k笔 交易。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

*/
#include <iostream>
#include <vector>
#include<climits>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int m=prices.size();
        vector<vector<int>> f(m+1,vector<int>(k+1,-0x3f3f3f3f));//当天处于买状态
        vector<vector<int>> g(m+1,vector<int>(k+1,-0x3f3f3f3f));//当天处于卖状态
        f[0][0]=-prices[0];
        g[0][0]=0;
        for(int i=1;i<=m;i++){
            for(int j=0;j<=k;j++)
            {
                f[i][j]=max(f[i-1][j],g[i-1][j]-prices[i-1]);
                g[i][j]=g[i-1][j];
                if(j-1>=0)
                    g[i][j]=max(g[i-1][j],f[i-1][j-1]+prices[i-1]);
            }
        }
        int ret=0;
        for(int i=0;i<=k;i++)
        {
            ret=max(ret,g[m][i]);
        }
        return ret;
    }
};