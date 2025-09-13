//面试题 17.16. 按摩师
//https://leetcode.cn/problems/the-masseuse-lcci/
//一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。
//在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。
//给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。
//示例：
//输入： [1,2,3,1]
//输出： 4
//解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。
#include <iostream>
#include <vector>
#include<climits>
#include<algorithm>
using namespace std;
class Solution {
public:
    int massage(vector<int>& nums) {
        int n=nums.size();
        vector<int> f(n+1);
        vector<int> g(n+1);
        for(int i=1;i<=n;i++)
        {
            f[i]=g[i-1]+nums[i-1];
            g[i]=max(g[i-1],f[i-1]);
        }
        return max(f[n],g[n]);
    }
};