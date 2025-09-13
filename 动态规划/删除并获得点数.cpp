//740. 删除并获得点数
//https://leetcode.cn/problems/delete-and-earn/description/
//给你一个整数数组 nums ，你可以对它进行一些操作。

//每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。
//之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。

//开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
//示例：
//输入：nums = [3,4,2]
//输出：6
//解释：
//删除 4 获得 4 个点数，因此 3 也被删除。
//之后，删除 2 获得 2 个点数。总共获得 6 个点数。
#include <iostream>
#include <vector>
#include<climits>
#include<algorithm>
using namespace std;
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        int N=10001;
        int arr[10001]={0};
        for(int e:nums)
        {
            arr[e]+=e;
        }
        vector<int> f(N+1,0);
        vector<int> g(N+1,0);
        f[0]=arr[0];
        for(int i=1;i<=N;i++)
        {
            f[i]=g[i-1]+arr[i-1];
            g[i]=max(g[i-1],f[i-1]);
        }
        return max(f[N],g[N]);
    }
};