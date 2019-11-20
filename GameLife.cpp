//
// Created by Liang on 2019-08-28.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void gameOfLifeV2(vector<vector<int>>& board){
        int m = board.size();
        int n = board[0].size();
        if(m == 0 || n == 0)
            return;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count = 0;
                for(int x=-1;x<=1;x++){
                    for(int y=-1;y<=1;y++){
                        if(x == 0 && y == 0)
                            continue;
                        int new_x = i + x;
                        int new_y = j + y;
                        if(new_x >=0 && new_x < m && new_y >=0 && new_y < n && (abs(board[new_x][new_y]) == 1)){
                            count += 1;
                        }
                    }
                }
                if(board[i][j] == 1 && (count < 2 || count > 3)){
                    board[i][j] = -1;
                }
                else{
                    if(board[i][j] == 0 && count == 3){
                        board[i][j] = 2;
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] > 0){
                    board[i][j] = 1;
                }else{
                    board[i][j] = 0;
                }
            }
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        if(m == 0 || n == 0)
            return;
        int count_life[m][n];
        memset(count_life, 0, sizeof(count_life));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count = 0;
                for(int x=-1;x<=1;x++){
                    for(int y=-1;y<=1;y++){
                        if(x == 0 && y == 0)
                            continue;
                        int new_x = i + x;
                        int new_y = j + y;
                        if(new_x >=0 && new_x < m && new_y >=0 && new_y < n){
                            count += board[new_x][new_y];
                        }
                    }
                }
                count_life[i][j] = count;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<count_life[i][j]<<",";
            }
            cout<<endl;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 1){
                    if(count_life[i][j] < 2 or count_life[i][j] > 3){
                        board[i][j] = 0;
                        continue;
                    }
                }else{
                    if(count_life[i][j] == 3){
                        board[i][j] = 1;
                        continue;
                    }
                }
            }
        }
    }
};
