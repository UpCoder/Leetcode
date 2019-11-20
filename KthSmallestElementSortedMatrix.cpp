#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
private:
    struct Point{
        int x, y, val;
        Point(int a, int b, int c){
            x = a;
            y = b;
            val = c;
        }
    };
    struct cmp{
    public:
        bool operator()(Point a, Point b){
            if(a.val > b.val){
                return true;
            }
            return false;
        }
    };
public:
    int kthSmallestPriorityQueue(vector<vector<int>>& matrix, int k){
        priority_queue<Point, vector<Point>, cmp> queue;
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            queue.push(Point(i, 0, matrix[i][0]));
        }
        int count = 0;
        while(count < (k-1)){
            count += 1;
            Point point = queue.top();
            queue.pop();
            if(point.y < (n-1)){
                queue.push(Point(point.x, point.y+1, matrix[point.x][point.y + 1]));
            }

        }
        return queue.top().val;
    }
    int kthSmallestBinarySearch(vector<vector<int>>& matrix, int k){
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        int low = matrix[0][0];
        int high = matrix[m-1][n-1];
        int count = 0;
        while(count < k){

        }
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> nums;
        int m = matrix.size();
        int n = matrix[0].size();
        if(m == 0 || n == 0)
            return 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                nums.push_back(matrix[i][j]);
            }
        }
        sort(nums.begin(), nums.end());
        return nums[k-1];
    }
    static void solution(){
        vector<vector<int>> matrix = {
                {1, 5, 9},
                {10, 11, 13},
                {11, 13, 15},
        };
        int k = 8;
        Solution solution1;
        cout<<solution1.kthSmallestPriorityQueue(matrix, 8)<<endl;
    }
};