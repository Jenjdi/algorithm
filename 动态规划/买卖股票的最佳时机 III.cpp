//123. 买卖股票的最佳时机 III
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/
/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

示例 1:

输入：prices = [3,3,5,0,0,3,1,4]
输出：6
解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，
这笔交易所能获得利润 = 3-0 = 3 。
随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
*/
#include <iostream>
#include <vector>
#include<climits>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m=prices.size();
        vector<int> dp(m+1);
        vector<vector<int>> f(m+1,vector<int>(3,-0x3f3f3f3f));
        vector<vector<int>> g(m+1,vector<int>(3,-0x3f3f3f3f));
        f[0][0]=-prices[0];
        g[0][0]=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<=2;j++)
            {
                f[i][j]=max(f[i-1][j],g[i-1][j]-prices[i-1]);
                g[i][j]=g[i-1][j];
                if(j-1>=0)
                    g[i][j]=max(g[i-1][j],f[i-1][j-1]+prices[i-1]);
            }
        }
        return max(g[m][0],max(g[m][1],g[m][2]));//因为f数组本身不会产生任何利润，只有浮盈，只有卖出去到g数组才是真正的利润
    }
};
