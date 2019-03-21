//
// Created by 梁栋 on 2019-03-19.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int j=0;j<n;j++){
            for(int i=0;i<n/2;i++){
                swap(matrix[i][j], matrix[n-i-1][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
class RotateImage{
public:
    static void test(){
        vector<vector<int> > matrix = {
                {5, 1, 9,11},
                {2, 4, 8,10},
                {13, 3, 6, 7},
                {15,14,12,16}
        };
        Solution solution;
        solution.rotate(matrix);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                cout<<matrix[i][j]<<", ";
            }
            cout<<endl;
        }
    }
};