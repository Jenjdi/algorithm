#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// 53. 最大子序和
// https://leetcode.cn/problems/maximum-subarray/
// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
// 子数组 是数组的 连续 部分。
// 示例:
// 输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
// 输出: 6
// 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
// 示例 2:
// 输入: nums = [1]
// 输出: 1
// 示例 3:
// 输入: nums = [5,4,-1,7,8]
// 输出: 23
// 提示：
// 1 <= nums.length <= 3 * 104
// -105 <= nums[i] <= 105
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n=nums.size();
            vector<int> dp(n+1);
            int ret=INT_MIN;
            for(int i=1;i<=n;i++)
            {
                dp[i]=max(nums[i-1],dp[i-1]+nums[i-1]);
                ret=max(ret,dp[i]);
            }
            return ret;
        }
    };