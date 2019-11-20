//
// Created by Liang on 2019-07-18.
//
#include <iostream>
#include <vector>
#include <stack>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if(T.size() == 0)
            return {};
        vector<int> res(T.size());
        stack<pair<int, int >> keep;
        int count = 0;
        int interval = 0;
        for(auto t: T){
            pair<int, int> cur_pair(t, count);
            if(keep.empty()){
                keep.push(cur_pair);
                count += 1;
                continue;
            }else{
                while(!keep.empty()){
                    pair<int, int> tmp = keep.top();
                    if(cur_pair.first > tmp.first){
                        res[tmp.second] = cur_pair.second - tmp.second;
                        keep.pop();

                        continue;
                    }else{
                        break;
                    }
                }
                keep.push(cur_pair);
            }
            count += 1;
        }
        return res;
    }
    static void solution(){
        Solution solution1;
        vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
        vector<int> res = solution1.dailyTemperatures(T);
        for(auto i: res){
            cout<<i<<", ";
        }
        cout<<endl;
    }
};