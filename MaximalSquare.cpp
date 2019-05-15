//
// Created by 梁栋 on 2019-05-15.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        int max = 0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(matrix[i-1][j-1] == '1'){
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    max = max > dp[i][j] ? max: dp[i][j];
                }
            }
        }
        return max * max;
    }
    int maximalSquareV2(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        vector<int> pre(n+1, 0);
        vector<int> cur(n+1, 0);
        int max = 0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(matrix[i-1][j-1] == '1'){
                    cur[j] = min(cur[j-1], min(pre[j], pre[j-1])) + 1;
                    max = max > cur[j] ? max: cur[j];
                }else{
                    cur[j] = 0;
                }
            }
            cout<<max<<endl;
            fill(pre.begin(), pre.end(), 0);
            swap(pre, cur);
        }
        return max * max;
    }
    static void solution(){
        Solution solution1;
        vector<vector<char >> input = {
                {'1', '0', '1', '0', '0'},
                {'1', '0', '1', '1', '1'},
                {'1', '1', '1', '1', '1'},
                {'1', '0', '0', '0', '0'}
        };
        cout<<solution1.maximalSquare(input)<<endl;
        cout<<solution1.maximalSquareV2(input)<<endl;
    }
};