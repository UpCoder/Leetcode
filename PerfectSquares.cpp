//
// Created by 梁栋 on 2019-05-16.
//
#include <cmath>
#include <iostream>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 0; // 0
        dp[1] = 1; // 1
        for(int i=2;i<=n;i++){
            int x = (int) sqrt(i);
            int cur_res = n;
            // 代表所能使用的所有perfect number
            for(int y=1;y<=x;y++){
                // 计算所有能用的perfect number 之间的最小值
                cur_res = min(cur_res, dp[i - y * y]);
            }
            dp[i] = cur_res + 1;
            cout<<(i)<<", "<<dp[i]<<endl;
        }
        return dp[n];
    }
    static void solution(){
        Solution solution1;
        cout<<solution1.numSquares(13)<<endl;
    }
};