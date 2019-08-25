//
// Created by Liang on 2019-08-16.
//
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class Solution {
public:
    int dx[4]={1, 0, -1, 0};
    int dy[4]={0, 1, 0, -1};
    bool is_ok(int x, int y, int m, int n){
        if(x >= 0 && y >= 0 && x < m && y < n)
            return true;
        return false;
    }
    void solveCore(const vector<vector<char>>& board, int x, int y, bool* used, int m, int n, vector<pair<int, int>>& points, bool& is_bound){
        for(int i=0;i<4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(is_ok(new_x, new_y, m, n) && !used[new_x * n + new_y] && board[new_x][new_y] == 'O'){
                used[new_x * n + new_y] = true;
                pair<int, int> new_point = pair<int, int>(new_x, new_y);
                points.push_back(new_point);
                if(new_x == 0 || new_x == (m-1) || new_y == 0 || new_y == (n-1))
                    is_bound = true;
                solveCore(board, new_x, new_y, used, m, n, points, is_bound);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0)
            return;
        int n = board[0].size();
        bool used[m*n];
        memset(used, false, sizeof(used));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O' && !used[i*n +j]){
                    bool is_bound = false;
                    if(i == 0 || i == (m-1) || j == 0 || j == (n-1))
                        is_bound = true;
                    vector<pair<int, int>> points;
                    pair<int, int> new_pair = pair<int, int>(i, j);
                    points.push_back(new_pair);
                    used[i * n + j] = true;
                    solveCore(board, i, j, used, m, n, points, is_bound);
                    if(!is_bound){
                        for(int z=0;z<points.size();z++){
                            pair<int, int> cur_pair = points[z];
                            board[cur_pair.first][cur_pair.second] = 'X';
                        }
                    }
                }
            }
        }
    }
    static void solution(){
        vector<vector<char>> board = {
                {'O','O','O'},
                {'O','O','O'},
                {'O','O','O'},
        };
        Solution solution1;
        solution1.solve(board);
        for(auto row: board){
            for(auto col: row){
                cout<<col<<" ";
            }
            cout<<endl;
        }
    }
};