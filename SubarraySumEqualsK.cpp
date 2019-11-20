//
// Created by Liang on 2019-07-09.
//
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        if(size == 0)
            return 0;
        int count = 0;
        unordered_map<int, int> map1;
        int sum = 0;
        map1[0] = 1;
        // k = sum - (sum-k)
        for(auto i: nums){
            sum += i;
            count += map1[sum-k];
            map1[sum] += 1;
        }
        return count;
//        int dp[size];
//        memset(dp, 0, sizeof(dp));
//        dp[0] = nums[0];
//        int count = 0;
//        for(int i=0;i<size;i++){
//            dp[i] = nums[i];
//            if(dp[i] == k)
//                count += 1;
//            for(int j=i+1;j<size;j++){
//                dp[j] = dp[j-1] + nums[j];
//                if(dp[j] == k){
//                    count += 1;
//                }
//            }
//        }
//        return count;
    }
    static void solution(){
        vector<int> nums = {1, 1, 1};
        int k = 2;
        Solution solution1;
        cout<<solution1.subarraySum(nums, k)<<endl;
    }
};