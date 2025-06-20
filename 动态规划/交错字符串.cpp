// 97. 交错字符串
// https://leetcode.cn/problems/interleaving-string/
// 给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。
// 两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：
// s = s1 + s2 + ... + sn
// t = t1 + t2 + ... + tm
// |n - m| <= 1
// 交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
// 注意：a + b 意味着字符串 a 和 b 连接。
// 示例 1：
// 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// 输出：true
// 示例 2：

// 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// 输出：false
// 示例 3：

// 输入：s1 = "", s2 = "", s3 = ""
// 输出：true
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            int m=s1.size();
            int n=s2.size();
            if(m+n!=s3.size())
            {
                return false;
            }
            s1=" "+s1;
            s2=" "+s2;
            s3=" "+s3;
            vector<vector<bool>> dp(m+1,vector<bool>(n+1));
            dp[0][0]=true;
            for(int i=1;i<=m;i++)
            {
                if(s1[i]==s3[i])
                {
                    dp[i][0]=true;
                }
                else{
                    break;
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(s2[i]==s3[i])
                {
                    dp[0][i]=true;
                }
                else{
                    break;
                }
            }
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    dp[i][j]=((s1[i]==s3[i+j]&&dp[i-1][j]==true)||(s2[j]==s3[i+j]&&dp[i][j-1]==true));
                }
            }
            return dp[m][n];
        }
    };