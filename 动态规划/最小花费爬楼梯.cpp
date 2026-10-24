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
    // 使用滚动状态；允许从第 1 级开始，长度不足 2 时无需支付费用。
    int previousCost = 0;
    int currentCost = 0;
    for (size_t step = 2; step <= cost.size(); ++step)
    {
        const int nextCost = min(currentCost + cost[step - 1],
                                 previousCost + cost[step - 2]);
        previousCost = currentCost;
        currentCost = nextCost;
    }
    return currentCost;
}
