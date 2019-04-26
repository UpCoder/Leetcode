//
// Created by 梁栋 on 2019-04-26.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isVaild(int x, int y, int m, int n){
        if(x>=0 && x<m && y>=0 && y<n){
            return true;
        }
        return false;
    }
    int dxs[4] = {1, 0, -1, 0};
    int dys[4] = {0, 1, 0, -1};
    void uniquePathsIIIRecursive(const vector<vector<int>>& grid, int m, int n, int x, int y, int step,
            int total_step, bool* visits, int& res){
        // cout<<x<<", "<<y<<endl;
        if(step == total_step){
            if(grid[x][y] == 2)
                res += 1;
            return;
        }
        if(grid[x][y] == 2){
            return;
        }
        for(int dir_id=0;dir_id<4;dir_id++){
            int new_x = x + dxs[dir_id];
            int new_y = y + dys[dir_id];
            if(isVaild(new_x, new_y, m, n)){
                int visit_pos = new_x * n + new_y;
                if(!visits[visit_pos] && grid[new_x][new_y] != -1){
                    visits[visit_pos] = true;
                    uniquePathsIIIRecursive(grid, m, n, new_x, new_y, step + 1, total_step, visits, res);
                    visits[visit_pos] = false;
                }
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = (int) grid.size();
        if(m == 0){
            return 0;
        }
        int n = (int) grid[0].size();
        bool visits[m * n];
        memset(visits, false, sizeof(visits));
        int total_step = 0;
        int start_x = 0;
        int start_y = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0 || grid[i][j] == 2){
                    total_step += 1;
                }
                if(grid[i][j] == 1){
                    start_x = i;
                    start_y = j;
                }
            }
        }
        int res = 0;
        visits[start_x * n + start_y] = true;
        uniquePathsIIIRecursive(grid, m, n, start_x, start_y, 0, total_step, visits, res);
        return res;
    }
    int code(int x, int y, int m, int n){
        return 1 << (x * n + y);
    }
    int uniquePathsIII_V2(vector<vector<int>>& grid) {
        int m = (int) grid.size();
        if(m == 0){
            return 0;
        }
        int n = (int) grid[0].size();
        int start_x;
        int start_y;
        int target_x;
        int target_y;
        int target = 0;
        for(int i=0;i<m;i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    target |= code(i, j, m, n);
                } else {
                    if (grid[i][j] == 1) {
                        start_x = i;
                        start_y = j;
                    } else {
                        if (grid[i][j] == 2) {
                            target |= code(i, j, m, n);
                            target_x = i;
                            target_y = j;
                        }
                    }
                }
            }
        }
        return dp(start_x, start_y, m, n, target_x, target_y, target);
    }
    int dp(int x, int y, int m, int n, int target_x, int target_y, int to_do){
        if(to_do == 0){
            if(x == target_x && y == target_y)
                return 1;
            return 0;
        }
        if(x == target_x && y == target_y)
            return 0;
        int ans = 0;
        for(int i=0;i<4;i++){
            int new_x = x + dxs[i];
            int new_y = y + dys[i];
            if(isVaild(new_x, new_y, m, n)){
                if(to_do & code(new_x, new_y, m, n))
                    ans += dp(new_x, new_y, m, n, target_x, target_y, to_do ^ code(new_x, new_y, m, n));
            }
        }
        return ans;
    }
    static void solution(){
        Solution solution1;
        vector<vector<int>> input = {
                {1,0,0,0},
                {0,0,0,0},
                {0,0,2,-1}

//                {1,0,0,0},
//                {0,0,0,0},
//                {0,0,0,2}
//                {0, 1},
//                {2, 0}
        };
        cout<<solution1.uniquePathsIII_V2(input)<<endl;
    }
};