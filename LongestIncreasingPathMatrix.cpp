//
// Created by Liang on 2019-08-26.
//

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    bool ok_xy(int x, int y, int m, int n){
        if(x < 0 || x >=m || y < 0 || y >= n)
            return false;
        return true;
    }

    int longestIncreasingPathCore(const vector<vector<int>>& matrix, bool* used, int x, int y, int m, int n, int* max_count){
        int num_solution = 1;
        for(int i=0;i<4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(!ok_xy(new_x, new_y, m, n))
                continue;
            if(used[new_x * n + new_y])
                continue;
            if(matrix[new_x][new_y] <= matrix[x][y]){
                continue;
            }
            if(max_count[new_x*n + new_y]!=0){
                num_solution = max(num_solution, max_count[new_x * n + new_y] + 1);
            }else{
                used[new_x*n + new_y] = true;
                int tmp = longestIncreasingPathCore(matrix, used, new_x, new_y, m, n, max_count);
                max_count[new_x * n + new_y] = tmp;
                num_solution = max(num_solution, max_count[new_x * n + new_y] + 1);
                used[new_x*n + new_y] = false;
            }
        }
        return num_solution;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        int max_count[m*n];
        memset(max_count, 0, sizeof(max_count));
        int result = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                bool used[m * n];
                memset(used, false, sizeof(used));
                result = max(result, longestIncreasingPathCore(matrix, used, i, j, m, n, max_count));
            }
        }
        return result;
    }
    static void solution(){
        vector<vector<int>> nums = {
//                {9,9,4},
//                {6,6,8},
//                {2,1,1}
                {3,4,5},
                {3,2,6},
                {2,2,1}
        };
        Solution solution1;
        cout<<solution1.longestIncreasingPath(nums)<<endl;
    }
};