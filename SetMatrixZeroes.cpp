//
// Created by Liang on 2019-08-08.
//
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0){
            return;
        }
        int n = matrix[0].size();
        bool zero_first_row = false;
        bool zero_first_col = false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    if(i == 0){
                        zero_first_row = true;
                    }
                    if(j == 0){
                        zero_first_col = true;
                    }
                }
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(zero_first_row){
            for(int j=0;j<n;j++){
                matrix[0][j] = 0;
            }
        }
        if(zero_first_col){
            for(int i=0;i<m;i++)
                matrix[i][0] = 0;

        }
    }
    static void solution(){
        vector<vector<int> > input_matrix = {
                {1,0,2,3},
//                {3,4,5,2},
//                {1,3,1,5}
        };
        Solution solution1;
        solution1.setZeroes(input_matrix);
        for(auto row: input_matrix){
            for(auto col: row){
                cout<<col<<",";
            }
            cout<<endl;
        }
    }
};