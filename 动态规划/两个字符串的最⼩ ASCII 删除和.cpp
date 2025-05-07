// 给定两个字符串s1 和 s2，返回 使两个字符串相等所需删除字符的 ASCII 值的最小和 。
// 示例 1:
// 输入: s1 = "sea", s2 = "eat"
// 输出: 231
// 解释: 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
// 在 "eat" 中删除 "t" 并将 116 加入总和。
// 结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
// 示例 2:
// 输入: s1 = "delete", s2 = "leet"
// 输出: 403
// 解释: 在 "delete" 中删除 "dee" 字符串变成 "let"，
// 将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
// 结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
// 如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417 的结果，比答案更大。
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int minimumDeleteSum(string s1, string s2) {
            int m=s1.size();
            int n=s2.size();
            vector<vector<int>> dp(m+1,vector<int>(n+1,0));
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    if(s1[i-1]==s2[j-1])
                    {
                        dp[i][j]=max(dp[i][j],dp[i-1][j-1]+s1[i-1]);
                    }
                }
            }
            int sum=0;
            for(auto e:s1)
                sum+=e;
            for(auto e:s2)
                sum+=e;
            return sum-2*dp[m][n];
        }
    };