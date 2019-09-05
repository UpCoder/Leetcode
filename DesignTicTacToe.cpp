//
// Created by Liang on 2019-09-05.
//
#include <vector>
#include <iostream>
using namespace std;
class TicTacToe {
public:
    vector<int> row_0;
    vector<int> row_1;
    vector<int> col_0;
    vector<int> col_1;
    int xie_up_0;
    int xie_up_1;
    int xie_down_0;
    int xie_down_1;
    int n;
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->n = n;
        row_0 = vector<int>(n, 0);
        row_1 = vector<int>(n, 0);
        col_0 = vector<int>(n, 0);
        col_1 = vector<int>(n, 0);
        xie_up_0 = 0;
        xie_up_1 = 0;
        xie_down_0 = 0;
        xie_down_1 = 0;
    }
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(player == 1){
            row_0[row] += 1;
            col_0[col] += 1;
            if(row_0[row] == n || col_0[col] == n)
                return 1;
            if(row == col){
                xie_up_0 += 1;
                if(xie_up_0 == n){
                    return 1;
                }
            }
            if((row + col + 1) == n){
                xie_down_0 += 1;
                if(xie_down_0 == n)
                    return 1;
            }
        }else{
            row_1[row] += 1;
            col_1[col] += 1;
            if(row_1[row] == n || col_1[col] == n){
                return 2;
            }
            if(row == col){
                xie_up_1 += 1;
                if(xie_up_1 == n)
                    return 2;
            }
            if((row + col + 1) == n){
                xie_down_1 += 1;
                if(xie_down_1 == n)
                    return 2;
            }
        }
        return 0;
    }
};
/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */