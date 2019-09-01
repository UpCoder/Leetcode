//
// Created by 梁栋 on 2019-05-17.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = (int) prices.size();
        if(size == 0)
            return 0;
        int state_buy[size];
        int state_sell[size];
        state_buy[0] = -prices[0];
        state_sell[0] = 0;
        int res = 0;
        for(int i=1;i<size;i++){
            state_buy[i] = max(state_sell[i - 1] - prices[i], state_buy[i - 1]);
            state_sell[i] = state_buy[i-1] + prices[i];
            res = max(res, state_sell[i]);
        }
        return res;
    }
    int maxProfitV2(vector<int>& prices) {
        int size = (int) prices.size();
        if(size == 0)
            return 0;
        int dp[size + 1];
        memset(dp, 0, sizeof(dp));
        int res = 0;
        for(int i=size-1;i>=0;i--){
            int profit = 0;
            for(int j=i+1;j<size;j++){
                profit = max(profit, max(prices[j] - prices[i] + dp[j+1], dp[j]));

            }
            dp[i] = profit;
            res = max(profit, res);
        }
        return res;

    }
    int maxProfitV3(vector<int>& prices){
        int res = 0;
        int size = (int) prices.size();
        for(int i=1;i<size;i++){
            if(prices[i]>prices[i-1]){
                res += (prices[i]-prices[i-1]);
            }
        }
        return res;
    }
    int maxProfitV4(vector<int>& prices){
        int res = 0;
        int size = (int) prices.size();
        if(size == 0)
            return 0;
        int state_sell[size];
        int state_buy[size];
        memset(state_buy, 0, sizeof(state_buy));
        memset(state_sell, 0, sizeof(state_sell));
        state_buy[0] = -prices[0];
        state_sell[0] = -0x7FFFFFF;
        for(int i=1;i<size;i++){
            state_buy[i] = max(state_sell[i-1] - prices[i], max(state_buy[i-1], -prices[i]));
            state_sell[i] = max(state_buy[i-1] + prices[i], state_sell[i-1]);
            res = max(res, max(state_sell[i], state_buy[i]));
        }
        return res;
    }
    static void solution(){
        vector<int> prices = {7,6,4,3,1};
        Solution solution1;
        cout<<solution1.maxProfitV4(prices)<<endl;
    }
};