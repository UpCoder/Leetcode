//
// Created by 梁栋 on 2019-05-16.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();
        int x = 0;
        int y = n-1;
        while(x < m && y>=0){
            if(target[x][y] == target)
                return true;
            if(target[x][y] > target){
                y--;
                continue;
            }
            if(target[x][y] < target){
                x++;
                continue;
            }
        }
        return false;
    }
};