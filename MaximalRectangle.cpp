//
// Created by 梁栋 on 2019-04-30.
//
#include <vector>
#include <iostream>
using namespace std;
#define MAX_INF 0x7FFFFFFF
class Solution {
public:
    int largestRectangleAreaBase(const vector<int >& heights, int l, int r){
        if(l > r)
            return 0;
        int min_height = -1;
        int min_height_index = l;
        bool increase_sorted = true;
        bool decrease_sorted = true;
        for(int i=l;i<=r;i++){
            if(min_height == -1 || min_height > heights[i]){
                min_height = heights[i];
                min_height_index = i;
            }
            if(i != r && heights[i] > heights[i + 1]){
                increase_sorted = false;
            }
            if(i != r && heights[i] < heights[i + 1]){
                decrease_sorted = false;
            }
        }
        if(increase_sorted){
            int res = 0;
            for(int i=r;i>=l;i--){
                res = max(res, heights[i] * (r-i+1));
            }
            return res;
        }
        if(decrease_sorted){
            int res = 0;
            for(int i=l;i<=r;i++){
                res = max(res, heights[i] * (i-l+1));
            }
            return res;
        }
        int res = min_height * (r - l + 1);
        res = max(res, max(
                largestRectangleAreaBase(heights, l, min_height_index-1),
                largestRectangleAreaBase(heights, min_height_index + 1, r)));
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int l = 0;
        int r = (int) heights.size()-1;
        res = largestRectangleAreaBase(heights, l, r);
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = (int) matrix.size();
        if(m == 0)
            return 0;
        int n = (int) matrix[0].size();
        vector<int > heights(n);
        for(int i=0;i<n;i++)
            heights[i] = 0;
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                heights[j] = matrix[i][j] == '0' ? 0: heights[j] + 1;
            }
            res = max(res, largestRectangleArea(heights));
        }
        return res;
    }
    int maximalRectangleWithDP(vector<vector<char>>& matrix){
        // target: 计算一个矩阵中，全部由1组成的子矩阵的最大面积
        int m = (int) matrix.size();
        if(m == 0)
            return 0;
        int n = (int) matrix[0].size();
        int left[n];   // 针对每一行，如果该位置是1，则连续是1的，且位于最左边的位置
        int right[n]; // 针对每一行，如果该位置是1，则连续是1的，且位于最右边的位置
        int height[n]; // 针对每一行的，连续是1 的高度
        memset(left, 0, sizeof(left));
        for(int i=0;i<n;i++)
            right[i] = n;
        memset(height, 0, sizeof(height));
        int res = 0;
        for(int i=0;i<m;i++){
            // 遍历每一行
            int cur_left = 0;
            int cur_right = n-1;
            for(int j=n-1;j>=0;j--){
                if(matrix[i][j] == '1'){
                    right[j] = min(cur_right, right[j]);
                }else{
                    right[j] = n-1;
                    cur_right = j-1;
                }
            }
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1'){
                    left[j] = max(left[j], cur_left);
                    height[j] = height[j] + 1;
                }else{
                    left[j] = 0;
                    cur_left = j+1;
                    height[j] = 0;
                }
                res = max(res, (right[j] - left[j] + 1) * height[j]);
            }
            for(int j=0;j<n;j++){
                cout<<left[j]<<",";
            }
            cout<<endl;
            for(int j=0;j<n;j++){
                cout<<right[j]<<",";
            }
            cout<<endl;
            for(int j=0;j<n;j++){
                cout<<height[j]<<",";
            }
            cout<<endl;
            cout<<res<<endl<<endl;
            cout<<endl;
        }
        return res;
    }
    static void solution(){
        vector<vector<char>> matrix = {
                {'1','0','1','0','0'},
                {'1','0','1','1','1'},
                {'1','1','1','1','1'},
                {'1','0','0','1','0'}
//                {'0','1'}
        };
        Solution solution1;
        cout<<solution1.maximalRectangleWithDP(matrix)<<endl;
    }
};

