//714. 买卖股票的最佳时机含手续费
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
//给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。

//你可以无限次地完成交易，但是你每笔交易都需要付手续费。
//如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

//返回获得利润的最大值。

//注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
//示例：
//输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
//输出：8
//解释：能够达到的最大利润:  
//在此处买入 prices[0] = 1
//在此处卖出 prices[3] = 8
//在此处买入 prices[4] = 4
//在此处卖出 prices[5] = 9
//总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8
#include <iostream>
#include <vector>
#include<climits>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int m=prices.size();
        vector<int> dp(m+1,0);
        vector<int> f(m+1,0);//第i天处于买入
        vector<int> g(m+1,0);//第i天处于卖出
        f[0]-=prices[0];
        dp[0]=max(f[0],g[0]);
        for(int i=1;i<=m;i++)
        {
            f[i]=max(f[i-1],g[i-1]-prices[i-1]);//买入时扣手续费可能会导致多次扣除手续费
            //手续费是针对 "一笔完整交易" 收取的，而不是针对买入或卖出单一行为
            g[i]=max(g[i-1],f[i-1]+prices[i-1]-fee);
            dp[i]=max(f[i],g[i]);
        }
        return dp[m];
    }  
};