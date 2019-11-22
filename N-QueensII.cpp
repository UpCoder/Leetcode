//
// Created by 梁栋 on 2019-11-22.
//
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isOkXY(int x, int y, int n){
        if(x>=0 && x < n && y>=0 && y< n){
            return true;
        }
        return false;
    }
    bool NQueensCore(int n, int i, int* matrix, int* col, int* row, int& result){
        if(i >= n){
            result += 1;
            return true;
        }
        for(int j=0;j<n;j++){
            if(col[j] == 1){
                continue;
            }
            // if location is i,j
            int x=i, y=j;
            int dirs[4][2]={{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
            int r =1;
            bool used= false;
            while(true){
                int numMeetCond = 0;
                for(int k=0;k<4;k++){
                    int new_x = x + dirs[k][0] * r;
                    int new_y = y + dirs[k][1] * r;
                    if(isOkXY(new_x, new_y, n)){
                        numMeetCond += 1;
                        if(matrix[new_x * n + new_y] == 1){
                            used = true;
                            numMeetCond = 0;
                            break;
                        }
                    }
                }
                if(numMeetCond==0){
                    break;
                }
                r += 1;
            }
            if(used){
                continue;
            }
            col[j] = 1;
            row[i] = 1;
            matrix[i*n+j] = 1;

            NQueensCore(n, i+1,matrix,col,row, result);
            col[j] = 0;
            row[i] = 0;
            matrix[i*n+j] = 0;
        }
        return false;
    }

    int totalNQueens(int n) {
        int result = 0;
        for(int i=0;i<n;i++){
            int matrix[n*n];
            int col[n];
            int row[n];
            memset(matrix, 0, sizeof(matrix));
            memset(col, 0, sizeof(col));
            memset(row, 0, sizeof(row));
            matrix[i] = 1;
            col[i] = 1;
            row[0] = 1;
            bool is_right = NQueensCore(n, 1, matrix, col, row, result);
        }
        return result;
    }
    static void solution(){
        Solution solution1;
        int result = solution1.totalNQueens(4);
        cout<<result<<endl;
    }
};