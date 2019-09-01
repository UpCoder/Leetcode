//
// Created by 梁栋 on 2019-08-21.
//
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <cmath>
using namespace std;
bool cmp(vector<int> x, vector<int> y){
    if(x[0] < y[0]){
        return true;
    }
    if(x[0] == y[0] && x[1] < y[1])
        return true;
    return false;
}
class Solution {

public:
    long long max(long long x, long long y){
        if(x > y)
            return x;
        return y;
    }
    int gcd(int a, int b){
        if(b == 0)
            return a;
        return gcd(b, a % b);
    }

    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 0)
            return 0;
        int res = 0;
        sort(points.begin(), points.end(), cmp);
        for(int i=0;i<points.size();i++){
            vector<int> point_s = points[i];
            map<pair<int, int>, long long> count_map;
            pair<int, int> zero_dxdy(0, 0);
            for(int j=i;j<points.size();j++){
                vector<int> point_e = points[j];
                if(point_s[0] == point_e[0] && point_s[1] == point_e[1]){
                    count_map[zero_dxdy] = count_map[zero_dxdy] + 1;
                    res = max(res, count_map[zero_dxdy]);
                    continue;
                }
                int dx = point_e[0] - point_s[0];
                int dy = point_e[1] - point_s[1];
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                pair<int, int> cur_dxdy(dx, dy);
                count_map[cur_dxdy] = count_map[cur_dxdy] + 1;
                res = max(res, count_map[cur_dxdy] + count_map[zero_dxdy]);
            }
        }
        return res;
    }
    static void solution(){
        Solution solution1;
        vector<vector<int>> points = {
                {1, 1},
                {3, 2},
                {5, 3},
                {4, 1},
                {2, 3},
                {1, 4}
        };
        cout<<solution1.maxPoints(points);
    }
};
