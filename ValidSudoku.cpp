//
// Created by 梁栋 on 2019-01-27.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            int* flag = new int[9];
            memset(flag, 0, sizeof(int) * 9);
            for(int j=0;j<9;j++){
                char val_c = board[i][j];
                if(val_c == '.')
                    continue;
                int val = val_c - '1';
                if(flag[val] == 1){
                    return false;
                }else{
                    flag[val] = 1;
                }
            }
        }
        for(int i=0;i<9;i++){
            int* flag = new int[9];
            memset(flag, 0, sizeof(int) * 9);
            for(int j=0;j<9;j++){

                char val_c = board[j][i];
                if(val_c == '.')
                    continue;
                int val = val_c - '1';
                if(flag[val] == 1){
                    return false;
                }else{
                    flag[val] = 1;
                }
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                int* flag = new int[9];
                memset(flag, 0, sizeof(int) * 9);
                for(int x=0;x<3;x++){
                    for(int y=0;y<3;y++){
                        char val_c = board[i + x][j + y];
                        if(val_c == '.')
                            continue;
                        int val = val_c - '1';
                        if(flag[val] == 1){
                            return false;
                        }else{
                            flag[val] = 1;
                        }
                    }
                }
            }
        }
        return true;
    }
};
class ValidSudoku{
public:
    static void test(){
        vector<vector<char>> input = {
                {'8','3','.','.','7','.','.','.','.'},
                {'6','.','.','1','9','5','.','.','.'},
                {'.','9','8','.','.','.','.','6','.'},
                {'8','.','.','.','6','.','.','.','3'},
                {'4','.','.','8','.','3','.','.','1'},
                {'7','.','.','.','2','.','.','.','6'},
                {'.','6','.','.','.','.','2','8','.'},
                {'.','.','.','4','1','9','.','.','5'},
                {'.','.','.','.','8','.','.','7','9'}
        };
        Solution solution = Solution();
        cout<<solution.isValidSudoku(input)<<endl;
    }

};
