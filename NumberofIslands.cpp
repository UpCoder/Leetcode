//
// Created by 梁栋 on 2019-05-10.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
private:
    vector<int> dxs = {1, 0, -1, 0};
    vector<int> dys = {0, 1, 0, -1};
public:
    bool isOk(int x, int y, int m, int n){
        if(x>=0 && x < m && y>=0 && y<n)
            return true;
        return false;
    }
    void numIslandsBase(vector<vector<char>>& grid, int x, int y, const int& m, const int& n, bool* visited){
        for(int i=0;i<4;i++){
            int new_x = x + dxs[i];
            int new_y = y + dys[i];
            if(isOk(new_x, new_y, m, n)
            && grid[new_x][new_y] == '1' && !visited[new_x * n + new_y]){
                visited[new_x * n + new_y] = true;
                numIslandsBase(grid, new_x, new_y, m, n, visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = (int) grid.size();
        if(m == 0)
            return 0;
        int n = (int) grid[0].size();
        bool visited[m * n];
        memset(visited, 0, sizeof(visited));
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && !visited[i*n+j]){
                    res += 1;
                    visited[i*n+j] = true;
                    numIslandsBase(grid, i, j, m, n, visited);
                }
            }
        }
        return res;
    }
    static void solution(){
        vector<vector<char >> grids = {
                {'1', '1', '1', '1', '0'},
                {'1', '0', '0', '0', '0'},
                {'1', '0', '1', '0', '1'},
                {'1', '0', '0', '1', '0'},
        };
        Solution solution1;
        cout<<solution1.numIslands(grids)<<endl;
    }
};