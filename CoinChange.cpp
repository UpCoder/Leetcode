//
// Created by Liang on 2019-06-26.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        return coinChangeDP(coins, amount);
    }
    int coinChangeDP(vector<int>& coins, int amount){
        int dp[amount+1];
        bool right[amount + 1];
        for(int i=0;i<=amount;i++){
            dp[i] = -1;
            right[i] = false;
        }

        dp[0] = 0;
        right[0] = true;
        // dp[i] = max({dp[i-coins[j]], for j in len(coins)})
        sort(coins.begin(), coins.end());
        for(int i=0;i<=amount;i++){
            int tmp;
            for(int j=0;j<coins.size();j++){
                tmp = i - coins[j];
                if(tmp < 0)
                    break;
                if(!right[tmp])
                    continue;

                if(dp[i] == -1)
                    dp[i] = dp[tmp] + 1;
                else
                    dp[i] = min(dp[i], dp[tmp] + 1);
                right[i] = true;
            }
        }
        return dp[amount];
    }
    static void solution(){
        vector<int> nums = {3, 2, 4};
        Solution solution1;
        cout<<solution1.coinChange(nums, 5)<<endl;
        nums = {2};
        cout<<solution1.coinChange(nums, 3)<<endl;
    }
};