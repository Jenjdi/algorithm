#include <bits/stdc++.h>
// 回归测试：每个题目放入独立命名空间，避免 Solution 类重名。
namespace example0 {
#include "../贪心算法/摆动数列.cpp"
}
namespace example1 {
#include "../贪心算法/最大数.cpp"
}
namespace example2 {
#include "../贪心算法/柠檬水找零.cpp"
}
namespace example3 {
#include "../贪心算法/将数组和减半的最少操作次数.cpp"
}
namespace example4 {
#include "../并查集/省份数量.cpp"
}
namespace example5 {
#include "../并查集/等式方程的可满足性.cpp"
}
namespace example6 {
#include "../动态规划/买卖股票的最佳时机 IV.cpp"
}
namespace example7 {
#include "../动态规划/买卖股票的最佳时机 III.cpp"
}
namespace example8 {
#include "../动态规划/买卖股票的最佳时机含手续费.cpp"
}
namespace example9 {
#include "../动态规划/买卖股票的最佳时机含冷冻期.cpp"
}
namespace example10 {
#include "../动态规划/交错字符串.cpp"
}
namespace example11 {
#include "../动态规划/不同路径1.cpp"
}
namespace example12 {
#include "../动态规划/不同路径2.cpp"
}
namespace example13 {
#include "../动态规划/删除并获得点数.cpp"
}
namespace example14 {
#include "../动态规划/环形子数组的最大和.cpp"
}
namespace example15 {
#include "../动态规划/解码方法.cpp"
}
namespace example16 {
#include "../动态规划/最小路径和.cpp"
}
namespace example17 {
#include "../动态规划/地下城游戏.cpp"
}
namespace example18 {
#include "../动态规划/粉刷房子.cpp"
}
namespace example19 {
#include "../动态规划/正则表达式匹配.cpp"
}
namespace example20 {
#include "../动态规划/最大子数组和.cpp"
}
namespace example21 {
#include "../动态规划/打家劫舍2.cpp"
}
namespace example22 {
#include "../动态规划/珠宝的最高价值.cpp"
}
namespace example23 {
#include "../动态规划/按摩师.cpp"
}
namespace example24 {
#include "../动态规划/两个字符串的最⼩ ASCII 删除和.cpp"
}
namespace example25 {
#include "../动态规划/下降路径最小和.cpp"
}
#include "../动态规划/最小花费爬楼梯.cpp"
namespace moveZeroExample {
#include "../双指针/移动零.cpp"
}
int main() {
{ moveZeroExample::Solution s; vector<int> values={0,1,0,3,12};s.moveZeroes(values);assert((values==vector<int>{1,3,12,0,0})); values.clear();s.moveZeroes(values);assert(values.empty()); }
{ example0::Solution s; vector<int> a={};assert(s.wiggleMaxLength(a)==0);a={INT_MIN,INT_MAX,INT_MIN};assert(s.wiggleMaxLength(a)==3);a={1,7,4,9,2,5};assert(s.wiggleMaxLength(a)==6); }
{ example1::Solution s; vector<int> a={};assert(s.largestNumber(a)=="");a={3,30,34,5,9};assert(s.largestNumber(a)=="9534330");a={0,0};assert(s.largestNumber(a)=="0"); }
{ example2::Solution s; vector<int> a={5,5,5,10,20};assert(s.lemonadeChange(a));a={5,5,10,10,20};assert(!s.lemonadeChange(a)); }
{ example3::Solution s; vector<int> a={5,19,8,1};assert(s.halveArray(a)==3); }
{ example4::Solution s; vector<vector<int>> a={{1,1,0},{1,1,0},{0,0,1}};assert(s.findCircleNum(a)==2); }
{ example5::Solution s; vector<string>a={"a==b","b!=a"};assert(!s.equationsPossible(a)); }
{ example6::Solution s; vector<int>a={};assert(s.maxProfit(2,a)==0);a={3,2,6,5,0,3};assert(s.maxProfit(2,a)==7);assert(s.maxProfit(0,a)==0); }
{ example7::Solution s; vector<int>a={};assert(s.maxProfit(a)==0);a={3,3,5,0,0,3,1,4};assert(s.maxProfit(a)==6); }
{ example8::Solution s; vector<int>a={};assert(s.maxProfit(a,2)==0);a={1,3,2,8,4,9};assert(s.maxProfit(a,2)==8); }
{ example9::Solution s; vector<int>a={};assert(s.maxProfit(a)==0);a={1,2,3,0,2};assert(s.maxProfit(a)==3); }
{ example10::Solution s; assert(s.isInterleave("aabcc","dbbca","aadbbcbcac"));assert(!s.isInterleave("aabcc","dbbca","aadbbbaccc")); }
{ example11::Solution s; assert(s.uniquePaths(3,7)==28);assert(s.uniquePaths(0,2)==0); }
{ example12::Solution s; vector<vector<int>>a={};assert(s.uniquePathsWithObstacles(a)==0);a={{0,0,0},{0,1,0},{0,0,0}};assert(s.uniquePathsWithObstacles(a)==2); }
{ example13::Solution s; vector<int>a={3,4,2};assert(s.deleteAndEarn(a)==6);a={2,2,3,3,3,4};assert(s.deleteAndEarn(a)==9); }
{ example14::Solution s; vector<int>a={5,-3,5};assert(s.maxSubarraySumCircular(a)==10);a={-3,-2,-3};assert(s.maxSubarraySumCircular(a)==-2); }
{ example15::Solution s; assert(s.numDecodings("226")==3);assert(s.numDecodings("06")==0); }
{ example16::Solution s; vector<vector<int>>a={};assert(s.minPathSum(a)==0);a={{1,3,1},{1,5,1},{4,2,1}};assert(s.minPathSum(a)==7); }
{ example17::Solution s; vector<vector<int>>a={{-2,-3,3},{-5,-10,1},{10,30,-5}};assert(s.calculateMinimumHP(a)==7); }
{ example18::Solution s; vector<vector<int>>a={{17,2,17},{16,16,5},{14,3,19}};assert(s.minCost(a)==10); }
{ example19::Solution s; assert(s.isMatch("aab","c*a*b"));assert(!s.isMatch("mississippi","mis*is*p*."));assert(s.isMatch("","a*")); }
{ example20::Solution s; vector<int>a={-2,1,-3,4,-1,2,1,-5,4};assert(s.maxSubArray(a)==6); }
{ example21::Solution s; vector<int>a={};assert(s.rob(a)==0);a={1};assert(s.rob(a)==1);a={2,3,2};assert(s.rob(a)==3); }
{ example22::Solution s; vector<vector<int>>a={{1,3,1},{1,5,1},{4,2,1}};assert(s.jewelleryValue(a)==12); }
{ example23::Solution s; vector<int>a={2,7,9,3,1};assert(s.massage(a)==12); }
{ example24::Solution s; assert(s.minimumDeleteSum("sea","eat")==231); }
{ example25::Solution s; vector<vector<int>>a={{2,1,3},{6,5,4},{7,8,9}};assert(s.minFallingPathSum(a)==13); }
{vector<int>a={};assert(minCostClimbingStairs(a)==0);a={10,15,20};assert(minCostClimbingStairs(a)==15);}
std::cout << "28 个算法文件的回归用例通过\n";
}
