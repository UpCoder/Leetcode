//
// Created by Liang on 2019-06-25.
//
#include <vector>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
class Solution {
public:
    int maxCoinsCore(const vector<int>& nums, bool* flag, int count, int sum, int& final_sum){
        if(count == nums.size()) {
            final_sum = max(final_sum, sum);
            return 0;
        }
        for(int i=0;i<nums.size();i++){
            if(flag[i]){
                // 没有使用过
                int left = 1;
                for(int j=i-1;j>=0;j--){
                    if(flag[j]){
                        left = nums[j];
                        break;
                    }
                }
                int right = 1;
                for(int j=i+1;j<nums.size();j++){
                    if(flag[j]){
                        right = nums[j];
                        break;
                    }
                }
                int tmp_sum = nums[i] * left * right;
                flag[i] = false;
                maxCoinsCore(nums, flag, count + 1, sum + tmp_sum, final_sum);
                flag[i] = true;
            }
        }
        return 0;
    }
    int maxCoins(vector<int>& nums) {
//        int result = 0;
//        int size = nums.size();
//        if(size == 0)
//            return 0;
//        bool flags[size];
//        memset(flags, true, sizeof(flags));
//        maxCoinsCore(nums, flags, 0, 0, result);
//        return result;
        return maxCoinsDP(nums);
    }
    int maxCoinsDP(const vector<int>& nums){
        int size = nums.size();
        if(size == 0)
            return 0;
        int dp[size][size];
        memset(dp, 0, sizeof(dp));
        for(int len=0;len<=size;len++){
            for(int i=0,j=i+len;i<size && j<size;i++,j++){
                for(int k=i;k<=j;k++){
                    int left = 1;
                    int leftPart = 0;
                    int right = 1;
                    int rightPart = 0;
                    if((i-1) >= 0) left = nums[i-1];
                    if((j+1) < size) right = nums[j+1];
                    if((k-1) >= 0) leftPart = dp[i][k-1];
                    if((k+1) < size) rightPart = dp[k+1][j];
                    int tmp = max(dp[i][j], nums[k] * left * right + leftPart + rightPart);
                    dp[i][j] = tmp;
                }
            }
        }
//        for(int i=0;i<size;i++){
//            for(int j=i;j<size;j++){
//                for(int k=i;k<=j;k++){
//                    int left;
//                    int leftPart;
//                    if(k < 1){
//                        left = 1;
//                        leftPart = 0;
//                    }else{
//                        left = nums[k-1];
//                        leftPart = dp[i][k-1];
//                    }
//                    int right;
//                    int rightPart = 0;
//                    if(k >= (size-1)){
//                        right = 1;
//                        rightPart = 0;
//                    }else{
//                        right = nums[k+1];
//                        rightPart = dp[k+1][j];
//                    }
//                    int tmp = max(dp[i][j], nums[k] * left * right + leftPart + rightPart);
//                    dp[i][j] = tmp;
//                }
//            }
//        }
        return dp[0][size-1];
    }
    static void solution(){
        vector<int> nums = {3, 1, 5, 8};
        Solution solution1 = Solution();
        cout<<solution1.maxCoins(nums)<<endl;
    }
};