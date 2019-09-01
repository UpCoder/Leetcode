//
// Created by 梁栋 on 2019-05-17.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = (int) nums.size();
        if(size == 0)
            return 0;
        int dp[size];
        memset(dp, 0, sizeof(dp));
        int res = 0;
        for(int i=0;i<size;i++){
            for(int j=0;j<=i;j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                    res = max(res, dp[i]);
                }
            }
        }
        return res + 1;
    }
    int lengthOfLISV2(vector<int>& nums) {
        int size = (int) nums.size();
        if(size == 0)
            return 0;
        int dp[size]; // dp[i]表示以i开头的位置
        memset(dp, 0, sizeof(dp));
        int res = 0;
        for(int i=size-1;i>=0;i--){
            for(int j=i+1;j<size;j++){
                if(nums[i] <= nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                    res = max(res, dp[i]);
                }
            }
        }
        return res + 1;
    }
    int lengthOfLISV3(vector<int>& nums) {
        vector<int> saved_num;
        for(auto n: nums){
            auto it = lower_bound(saved_num.begin(), saved_num.end(), n);
            if(it == saved_num.end()){
                saved_num.push_back(n);
            }else{
                *it = n;
            }
        }
        return saved_num.size();
    }
    static void solution(){
        Solution solution1;
        vector<int> nums = {10,9,2,5,3,3,7,101,18};
        cout<<solution1.lengthOfLISV3(nums)<<endl;
    }
};