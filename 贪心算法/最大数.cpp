#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// 给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
// 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
// 示例 1：

// 输入：nums = [10,2]
// 输出："210"
// 示例 2：

// 输入：nums = [3,30,34,5,9]
// 输出："9534330"
class Solution {
    public:
    
        string largestNumber(vector<int>& nums) {
            vector<string> str;
            for(auto e:nums)
            {
                str.push_back(to_string(e));
            }
            sort(str.begin(),str.end(),[](const string& s1,const string& s2){
                return s1+s2>s2+s1;
            });
            string ret;
            for(auto e:str)
            {
                ret+=e;
            }
            if(str[0]=="0")
            {
                return "0";
            }
            return ret;
        }
    };