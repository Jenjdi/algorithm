#include <iostream>
#include <vector>
using namespace std;
//746. 使用最小花费爬楼梯
//题目链接：https://leetcode.cn/problems/min-cost-climbing-stairs/
//给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。
//一旦你支付此费用，即可选择向上爬一个或者两个台阶。
//你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
//请你计算并返回达到楼梯顶部的最低花费。
//示例：
//输入：cost = [10,15,20]
//输出：15
//解释：你将从下标为 1 的台阶开始。
//- 支付 15 ，向上爬两个台阶，到达楼梯顶部。
//总花费为 15

int minCostClimbingStairs(vector<int> &cost)
{
    // write code here
    int n = cost.size();
    if (n <= 2)
    {
        return min(cost[0], cost[1]);
    }
    vector<int> dp(n);
    dp[0] = dp[1] = 0;
    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return min(dp[n - 1] + cost[n - 1], dp[n - 2] + cost[n - 2]);
}