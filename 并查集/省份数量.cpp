//有 n 个城市，其中一些彼此相连，另一些没有相连。
//如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。
//省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
//给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，
//而 isConnected[i][j] = 0 表示二者不直接相连。
//返回矩阵中 省份 的数量。


//利用了并查集，将同一组，也就是同一个省份的合并在一起
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m=isConnected.size();
        vector<int> ufs(m,-1);
        auto findroot=[&ufs](int x)
        {
            while(ufs[x]>=0)
            {
                x=ufs[x];
            }
            return x;
        };
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<isConnected[i].size();j++)
            {
                if(isConnected[i][j]==1)
                {
                    int root1=findroot(i);
                    int root2=findroot(j);
                    if(root1!=root2)
                    {
                        ufs[root1]+=ufs[root2];
                        ufs[root2]=root1;
                    }//将两个相连的城市合并在同一个根下面
                    
                }
            }
        }
        int ret=0;
        for(int i=0;i<ufs.size();i++)
        {
            if(ufs[i]<0)
                ret++;
        }
        return ret;
    }
};
