//
// Created by 梁栋 on 2019-05-02.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int low_price = prices[0];
        int profit = 0;
        for(int i=1;i<prices.size();i++){
            profit = max(profit, prices[i] - low_price);
            if(low_price > prices[i])
                low_price = prices[i];
        }
        return profit;
    }
};