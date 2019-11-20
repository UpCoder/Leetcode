//
// Created by Liang on 2019-07-06.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
    bool canPartitionCore(const vector<int>& nums, int sum, int target, bool* used, int start_id){
        if(sum == target)
            return true;
        if(sum > target)
            return false;
        for(int i=start_id;i<nums.size();i++){
            int diff = target - sum;
            if(diff < nums[i])
                return false;
            if(used[i]){
                used[i] = false;
                bool res_flag = canPartitionCore(nums, sum + nums[i], target, used, start_id);
                if(res_flag)
                    return true;
                used[i] = true;
            }
        }
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        if(nums.size() == 0)
            return true;
        int sum = 0;
        for(auto e: nums){
            sum += e;
        }
        if(sum % 2 != 0)
            return false;
        sort(nums.begin(), nums.end());
//        bool used[nums.size()];
//        memset(used, 1, sizeof(used));
        //return canPartitionCore(nums, 0, sum / 2, used, 0);
        int target = sum / 2;
        if(nums[size-1] > target)
            return false;
        int dp[target + 1];
        for(int i=0;i<=target;i++){
            dp[i] = 10000000;
        }
        dp[0] = 0;
        for(int i=0;i<size;i++){
            for(int j=target;j>=nums[i];j--){
                int tmp = min(dp[j - nums[i]] + 1, dp[j]);
                dp[j] = tmp;
            }
        }
//        for(int i=1;i<=target;i++){
//            int tmp = size + 1;
//            for(int j=0;j<size;j++){
//                if((i - nums[j]) < 0)
//                    break;
//                tmp = min(dp[i-nums[j]] + 1, tmp);
//            }
//            dp[i] = tmp;
//        }
        // cout<<dp[target]<<endl;
        return dp[target] != 10000000;
    }
    static void solution(){
        Solution solution1;
//        vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
//                            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
//                            ,1,1,100};
        vector<int> nums = {2, 2, 3, 5};
        cout<<solution1.canPartition(nums)<<endl;
    }
};