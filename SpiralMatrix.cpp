//
// Created by Liang on 2019-07-28.
//
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return {};
        int n = matrix[0].size();
        if(n == 0)
            return {};
        int x, y;
        x = y = 0;
        vector<int> res;
        int count = 0;
        while(true){
            int end_x = m - count;
            int end_y = n - count;
            // to left
            while(y < end_y && x < end_x){
                res.push_back(matrix[x][y]);
                y++;
            }
            y = end_y - 1; // 最后一列
            x += 1; // 向下移动一行
            // to down
            while(y < end_y && x < end_x){
                res.push_back(matrix[x][y]);
                x++;
            }
            x = end_x - 1; // 最后一行
            y -= 1; // 向左移动一列
            // to right
            while(y >= count && x >= count && (end_x - count) > 1){
                res.push_back(matrix[x][y]);
                y--;
            }
            y = count; // 第一列
            x -= 1; //向上移动一行
            // to up
            while(y >= count && x > count && (end_y - count) > 1){
                res.push_back(matrix[x][y]);
                x--;
            }
            if(res.size() == m*n){
                break;
            }
            count += 1;
            x = count;
            y = count;
        }
        return res;
    }

    static void solution(){
        vector<vector<int> > input = {
                {1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12 }
        };
        Solution solution1;
        vector<int> res = solution1.spiralOrder(input);
        for(auto r: res){
            cout<<r<<",";
        }
        cout<<endl;
    }
};