//
// Created by 梁栋 on 2019-04-26.
//
#include <iostream>
using namespace std;
class Solution {
public:
    int dxs[2] = {1, 0};
    int dys[2] = {0, 1};
    bool isVaild(int x, int y, int m, int n){
        if(x>=0 && x<m && y>=0 && y<n){
            return true;
        }
        return false;
    }
    void uniquePathsRecursive(int m, int n, int x, int y, bool* visit, int& res){
        if(x==(m-1) && y==(n-1)){
            res += 1;
            return ;
        }
        for(int i=0;i<2;i++){
            int new_x = x + dxs[i];
            int new_y = y + dys[i];
            if(isVaild(new_x, new_y, m, n)){
                int visit_pos = new_x * n + new_y;
                if(!visit[visit_pos]){
                    visit[visit_pos] = true;
                    uniquePathsRecursive(m, n, new_x, new_y, visit, res);
                    visit[visit_pos] = false;
                }
            }
        }
    }
    int uniquePaths(int m, int n) {
        int res = 0;
//        bool visits[m * n];
//        memset(visits, false, sizeof(visits));
//        uniquePathsRecursive(m, n, 0, 0, visits, res);
        int dp[m][n];
        for(int i=0;i<m;i++){
            dp[i][0] = 1;
        }
        for(int j=0;j<n;j++){
            dp[0][j] = 1;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 || j == 0)
                    continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        res = dp[m-1][n-1];
        return res;
    }
    static void solution(){
        Solution solution1;
        cout<<solution1.uniquePaths(22, 33)<<endl;
    }
};