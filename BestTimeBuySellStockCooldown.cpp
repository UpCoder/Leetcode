//
// Created by 梁栋 on 2019-05-17.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = (int) prices.size();
        if(size == 0)
            return 0;
        int profits[size]; // 代表从第i点买入所能获得的收益
        memset(profits, 0, sizeof(profits));
        int res = 0;
        for(int i=size-1;i>=0;i--){
            int profit = 0;
            for(int j=i+1;j<size;j++){
                // 某时刻卖出
                if((j+2) < size)
                    profit = max(prices[j] - prices[i] + profits[j+2], max(profit, profits[j]));
                else
                    profit = max(prices[j] - prices[i], max(profit, profits[j]));

            }

            profits[i] = profit;
            res = max(res, profit);
        }
        return res;
    }
    int maxProfitV2(vector<int>& prices){
        int size = (int) prices.size();

        if(size == 0)
            return 0;
        int state_reset[size];
        int state_buy[size];
        int state_sell[size];
        memset(state_reset, 0, sizeof(state_reset));
        memset(state_buy, 0, sizeof(state_buy));
        memset(state_sell, 0, sizeof(state_sell));
        state_reset[0] = 0;
        state_buy[0] = -prices[0];
        state_sell[0] = -0x7FFFFFFF;
        for(int i=1;i<size;i++){
            state_reset[i] = max(state_reset[i-1], state_sell[i-1]); // 维持上一个状态，即不买入，或者是上一个卖出的状态的最大值
            state_buy[i] = max(state_reset[i-1] - prices[i], state_buy[i-1]);   // reset状态过来，或者说不买入也不卖出
            state_sell[i] = state_buy[i-1] + prices[i]; // 卖出
        }
        return max(state_sell[size-1], max(state_reset[size-1], state_buy[size-1]));
    }
    static void solution(){
        vector<int> prices = {1, 2, 3, 0, 2};
        Solution solution1;
        cout<<solution1.maxProfitV2(prices)<<endl;
    }
};