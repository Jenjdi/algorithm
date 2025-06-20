// 10. 正则表达式匹配
// https://leetcode.cn/problems/regular-expression-matching/
// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
// '.' 匹配任意单个字符，而 '*' 匹配零个或多个前面的那一个元素。
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
// 说明:
// s 可能为空，且只包含小写字母。
// p 可能为空，且只包含小写字母和字符 . 和 *。
// 保证每次出现字符 * 时，前面都匹配到有效的字符
// 示例 1:
// 输入:
// s = "aa"
// p = "a"
// 输出: false
// 解释: "a" 无法匹配 "aa" 的所有字符。
// 示例 2:
// 输入:
// s = "aa"
// p = "a*"
// 输出: true
// 解释: '*' 代表零个或多个前面的元素,这里前面是 'a'.
// 因此可以认为 'a' 被重复了一次，所以可以匹配字符串 "aa"。
// 示例 3:
// 输入:
// s = "ab"
// p = ".*"
// 输出: true
// 解释: ".*" 表示可匹配零个或多个('*')的任意字符('.')。
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
    public:
        bool isMatch(string s, string p) {
            int m=s.size();
            int n=p.size();
            vector<vector<bool>> dp(m+1,vector<bool>(n+1));
            dp[0][0]=true;
            s=" "+s;
            p=" "+p;
            for(int i=2;i<=n;i+=2)
            {
                if(p[i]=='*')
                {
                    dp[0][i]=true;
                }
                else
                {
                    break;
                }
            }
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(p[j]!='*')
                    {
                        dp[i][j]=(p[j]==s[i]||p[j]=='.')&&dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]=dp[i][j-2]||(p[j-1]=='.'||p[j-1]==s[i])&&dp[i-1][j];
                    }
                }
            }
            return dp[m][n];
        }
    };