//
// Created by Liang on 2019-06-27.
//
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        if(num == 0)
            return {0};
        bool used[num+1];
        memset(used, 0, sizeof(used));
        vector<int> res(num+1);
        int x = 1;
        used[x] = false;
        res[x] = 1;
        countBitsCore(x, res, 1, used, num);
        return res;
    }
    void countBitsCore(int x, vector<int>& res, int count, bool* used, const int num){
        int new_x = x<<1;
        if(new_x < 0 || new_x > num)
            return;
        if(used[new_x] == false){
            res[new_x] = count;
            used[new_x] = true;
            countBitsCore(new_x, res, count, used, num);
        }
        new_x = ((x << 1) ^ 1);
        if(new_x < 0 || new_x > num)
            return;
        if(used[new_x] == false){
            used[new_x] = true;
            res[new_x] = count + 1;
            countBitsCore(new_x, res, count + 1, used, num);
        }

    }
    static void solution(){
        Solution solution1;
        vector<int> res = solution1.countBits(2);
        for (int i = 0; i < res.size(); ++i) {
            cout<<res[i]<<", ";
        }
        cout<<endl;
    }

};