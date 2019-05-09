//
// Created by 梁栋 on 2019-05-09.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = (int) nums.size();
        if(size == 0)
            return 0;
        int dp[size];
        memset(dp, 0, sizeof(dp));
        dp[0] = nums[0];
        int res = dp[0];
        for(int i=1;i<size;i++){
            if((i-2)>=0){
                dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
            }else{
                dp[i] = max(nums[i], dp[i-1]);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};