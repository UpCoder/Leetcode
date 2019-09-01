//
// Created by 梁栋 on 2019-05-17.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void maxProfitBase(vector<int>& prices, int flag, int count, int cur_profit, int cur,int& res){
        res = max(res, cur_profit);
        if(count >= 2 || cur >= prices.size()){
            return;
        }
        for(int i=cur;i<prices.size();i++){
            if(flag == 1){
                maxProfitBase(prices, 2, count, cur_profit-prices[i], i+1, res); // buy
                maxProfitBase(prices, 1, count, cur_profit, i+1, res); // not buy
            }else{
                if(flag == 2){
                    maxProfitBase(prices, 1, count + 1, cur_profit + prices[i], i + 1, res);
                    maxProfitBase(prices, 2, count, cur_profit, i + 1, res);
                }
            }
        }
    }
    int maxProfit(vector<int>& prices) {
        int res = 0;
        maxProfitBase(prices, 1, 0, 0, 0, res);
        return res;
    }
    int maxProfitV2(vector<int>& prices){
        int res = 0;
        int size = (int) prices.size();
        if(size == 0)
            return 0;
        int K = 2;
        int dp[K + 1][size + 1];
        memset(dp, 0, sizeof(dp));
        // dp[k][i] = max(dp[k][i-1], prices[i] - prices[j] + dp[k-1][j] for j ~[0, i-1])
        for(int k=1;k<=K;k++){
            for(int i=1;i<=size;i++){
                int profit = 0;
                for(int j=i-1;j>=1;j--){
                    profit = max(profit, max(dp[k][i-1], prices[i-1]-prices[j-1] + dp[k-1][j-1]));
                }
                dp[k][i] = profit;
                res = max(res, profit);
            }
        }
        return res;
    }
    int maxProfitV3(vector<int>& prices){
        int res = 0;
        int size = (int) prices.size();
        if(size == 0)
            return 0;
        int K = 2;
        int dp[K + 1][size + 1];
        memset(dp, 0, sizeof(dp));
        // dp[k][i] = max(dp[k][i-1], prices[i] - prices[j] + dp[k-1][j] for j ~[0, i-1])
        // dp[k][i] = max(dp[k][i-1], prices[i] + dp[k-1][j] - prices[j] for j ~[0, i-1])
        // dp[k][i] = max(dp[k][i-1], prices[i] + max(dp[k-1][j] - prices[j]))
        for(int k=1;k<=K;k++){
            int tmpMax = dp[k-1][0] - prices[0];
            for(int i=2;i<=size;i++){
                dp[k][i] = max(dp[k][i-1], prices[i-1] + tmpMax);
                tmpMax = max(tmpMax, dp[k-1][i-1] - prices[i-1]);
                res = max(dp[k][i], res);
            }
        }
        return res;
    }
    int maxProfitV4(vector<int>& prices){
        int len = prices.size();
        if (len<2) return 0;
        if (k>len/2){ // simple case
            int ans = 0;
            for (int i=1; i<len; ++i){
                ans += max(prices[i] - prices[i-1],0);
            }
            return ans;
        }
        int res = 0;
        int size = (int) prices.size();
        if(size == 0)
            return 0;
        int K = 100;
        int dp[size + 1];
        memset(dp, 0, sizeof(dp));
        // dp[k][i] = max(dp[k][i-1], prices[i] - prices[j] + dp[k-1][j-1] for j ~[0, i-1])
        // dp[k][i] = max(dp[k][i-1], prices[i] + dp[k-1][j-1] - prices[j] for j ~[0, i-1])
        // dp[k][i] = max(dp[k][i-1], prices[i] + max(dp[k-1][j-1] - prices[j]))
        for(int k=1;k<=K;k++){
            int tmpMax = dp[0] - prices[0];
            int saved_last = dp[1];
            for(int i=2;i<=size;i++){
                int tmp = dp[i];
                dp[i] = max(dp[i-1], prices[i-1] + tmpMax);
                tmpMax = max(tmpMax, saved_last - prices[i-1]);
                saved_last = tmp;
                res = max(dp[i], res);
            }
        }
        return dp[size];
    }
    static void solution(){
        vector<int> prices = {2, 1, 2, 0, 1};
        Solution solution1;
        cout<<solution1.maxProfitV4(prices)<<endl;
    }
};