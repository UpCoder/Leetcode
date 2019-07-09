//
// Created by Liang on 2019-07-07.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0)
            return 0;
        int size = nums.size();
        int total_sum = 0;
        for(auto i:nums){
            total_sum += i;
        }
        if(abs(S) > total_sum)
            return 0;
        int dp[size][(total_sum) * 2 + 1];
        memset(dp, 0, sizeof(dp));
//        for(auto i:nums){
//            dp[0][i + total_sum] = 1;
//            dp[0][-i + total_sum] = 1;
//        }
        dp[0][nums[0] + total_sum] += 1;
        dp[0][-nums[0] + total_sum] += 1;
        for(int i=1;i<size;i++){
            for(int j=0;j<(total_sum) * 2 + 1;j++){
                // cur sum is j
                int add_last_idx = j - nums[i]; // last + nums[i] = j
                int sub_last_idx = j + nums[i]; // last - nums[i] = j
                if(add_last_idx >= 0 && add_last_idx <(total_sum * 2 +1)){
                    if(sub_last_idx >= 0 && sub_last_idx < (total_sum * 2 + 1)){
                        dp[i][j] = dp[i-1][add_last_idx] + dp[i-1][sub_last_idx];
                    }else{
                        dp[i][j] = dp[i-1][add_last_idx];
                    }
                }else{
                    if(sub_last_idx >=0 && sub_last_idx < (total_sum * 2 + 1)){
                        dp[i][j] = dp[i-1][sub_last_idx];
                    }else{
                        dp[i][j] = 0;
                    }
                }
            }
        }
        for(int i=0;i<size;i++){
            for(int j=0;j<total_sum * 2 + 1;j++){
                cout<<dp[i][j]<<",";
            }
            cout<<endl;
        }
        return dp[size-1][S + total_sum];
    }
    static void solution(){
        Solution solution1;
//        vector<int> nums = {1, 1, 1, 1, 1};
//        int S = 3;
        vector<int> nums = {0,0,0,0,0,0,0,0,1};
        int S = 1;
        cout<<solution1.findTargetSumWays(nums, S)<<endl;
    }
};
