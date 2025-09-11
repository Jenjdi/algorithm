//给定一个由表示变量之间关系的字符串方程组成的数组，
//每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。
//在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。
//只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 

//示例：
//输入：["a==b","b!=a"]
//输出：false
//解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。

//先将相等的放入并查集中，再在并查集中查找不相等的，如果不相等的存在于并查集中，则返回false，否则满足条件
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> ufs(26,-1);
        auto findroot=[&ufs](int x)
        {
            while(ufs[x]>=0)
                x=ufs[x];
            return x;
        };
        for(int i=0;i<equations.size();i++)
        {
            if(equations[i][1]=='=')
            {
                int root1=findroot(equations[i][0]-'a');
                int root2=findroot(equations[i][3]-'a');
                if(root1!=root2)
                {
                    ufs[root1]+=ufs[root2];
                    ufs[root2]=root1;
                }
            }
        }
        for(int i=0;i<equations.size();i++)
        {
            if(equations[i][1]=='!')
            {
                int root1=findroot(equations[i][0]-'a');
                int root2=findroot(equations[i][3]-'a');
                if(root1==root2)
                    return false;
            }
        }
        return true;
    }
};