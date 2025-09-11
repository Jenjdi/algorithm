//给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。
//下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。
//在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。
//具体来说，位置 (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1) 。
//示例：
//输入：matrix = [[2,1,3],[6,5,4],[7,8,9]]
//输出：13
//解释：为和最小的两条下降路径
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        vector<vector<int>> dp(m+1,vector<int>(m+2));
        for(int i=1;i<=m;i++)
        {
            dp[i][0]=INT_MAX;
            dp[i][m+1]=INT_MAX;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]))+matrix[i-1][j-1];
            }
        }
        //return dp[m][m];
        //最后一行会有3个值，需要得到这三个中的最小值
        int ret=INT_MAX;
        for(int i=1;i<=m;i++)
        {
            ret=min(ret,dp[m][i]);
        }
        return ret;
    }
};