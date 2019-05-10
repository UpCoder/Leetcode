//
// Created by 梁栋 on 2019-05-09.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    int rob(const vector<int>& nums, int l, int r){
        int size = r - l + 1;
        int dp[size];
        memset(dp, 0, sizeof(dp));
        dp[0] = nums[l];
        int res = dp[0];
        for(int i=l+1; i<=r; i++){
            if((i-2) >= l){
                dp[i-l] = max(dp[i-l-2] + nums[i], dp[i-l-1]);
            }else{
                dp[i-l] = max(nums[i], dp[i-l-1]);
            }
            res = max(res, dp[i-l]);
        }
        return res;
    }
public:
    int rob(vector<int>& nums) {
        int size = (int) nums.size();
        return max(rob(nums, 0, size-2), rob(nums, 1, size-1));
    }
    static void solution(){
        Solution solution1;
        vector<int> input = {2, 3, 2};
        cout<<solution1.rob(input)<<endl;
    }
};