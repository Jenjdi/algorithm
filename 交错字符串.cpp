#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
// 97. 交错字符串
// https://leetcode.cn/problems/interleaving-string/
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