//
// Created by 梁栋 on 2019-01-27.
//

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    static void print(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<board[i][j]<<",";
            }
            cout<<endl;
        }
        cout<<"\n"<<endl;
    }
    bool generate_Sudo(vector<vector<char >>& board, vector<int*>& rows, vector<int*>& columns, vector<int*>& grids){
        //Solution::print(board);
        bool finished = true;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    finished = false;
                }
            }
        }
        if(finished){
            Solution::print(board);
            return true;
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    int grid_idx = (i / 3 ) * 3 + j / 3;
                    bool find_res = false;
                    for(int z=0;z<9;z++){
                        if(rows[i][z] == 0 && columns[j][z] == 0 && grids[grid_idx][z] == 0){
                            rows[i][z] = 1;
                            columns[j][z] = 1;
                            grids[grid_idx][z] = 1;
                            board[i][j] = char('1' + z);
                            if(generate_Sudo(board, rows, columns, grids)){
                                find_res = true;
                                return true;
                            }else{
                                rows[i][z] = 0;
                                columns[j][z] = 0;
                                grids[grid_idx][z] = 0;
                                board[i][j] = '.';
                            }
                        }
                    }
                    if(find_res == false){
                        return false;
                    }
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<int*> rows;
        vector<int*> columns;
        vector<int*> grids;
        for(int i=0;i<9;i++){
            int* row = new int[9];
            int* column = new int[9];
            int* grid = new int[9];
            memset(row, 0, sizeof(int) * 9);
            memset(column, 0, sizeof(int) * 9);
            memset(grid, 0, sizeof(int) * 9);
            rows.push_back(row);
            columns.push_back(column);
            grids.push_back(grid);
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char val_c = board[i][j];
                if(val_c == '.')
                    continue;
                int val = val_c - '1';
                rows[i][val] = 1;
                columns[j][val] = 1;
                int grid_idx = (i / 3 ) * 3 + j / 3;
                grids[grid_idx][val] = 1;
            }
        }
        bool solver_res = generate_Sudo(board, rows, columns, grids);
        cout<<"solver_res is "<<solver_res<<endl;
    }
};
class SodukuSolver{
public:
    static void test(){
        vector<vector<char>> input = {
//            {'5','3','.','.','7','.','.','.','.'},
//            {'6','.','.','1','9','5','.','.','.'},
//            {'.','9','8','.','.','.','.','6','.'},
//            {'8','.','.','.','6','.','.','.','3'},
//            {'4','.','.','8','.','3','.','.','1'},
//            {'7','.','.','.','2','.','.','.','6'},
//            {'.','6','.','.','.','.','2','8','.'},
//            {'.','.','.','4','1','9','.','.','5'},
//            {'.','.','.','.','8','.','.','7','9'}
                {'.','.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.','.'},
                {'.','.','.','.','.','.','.','.','.'}
        };
        Solution solution = Solution();
        solution.solveSudoku(input);
    }
};