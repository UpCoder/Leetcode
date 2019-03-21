//
// Created by 梁栋 on 2019-03-20.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = int(nums.size());
        int dp_max;
        int dp_min;
        dp_max = nums[0];
        dp_min = nums[0];
        int res = nums[0];
        for(int i=1;i<nums.size();i++){
            int cur_max = max(nums[i], max(dp_max * nums[i], dp_min * nums[i]));
            int cur_min = min(nums[i], min(dp_max * nums[i], dp_min * nums[i]));
            dp_max = cur_max;
            dp_min = cur_min;
            res = max(res, cur_max);
//            cout<<i<<", "<<dp_max<<", "<<dp_min<<endl;
        }
        return res;
    }
};
class MaximumProductSubarray{
public:
    static void test(){
        vector<int> nums = {-1,-3,-2,4};
        Solution solution;
        cout<<solution.maxProduct(nums)<<endl;
    }
};