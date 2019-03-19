//
// Created by 梁栋 on 2019-03-18.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void combinationSum2Base(const vector<int>& candidates, int start, int target, vector<int > record, vector<vector<int> >& res){
        if(target == 0){
            res.push_back(record);
            return ;
        }
        bool find_flag = false;
        for(int i=start;i<candidates.size() && target >= candidates[i];i++){
            if(record.empty() && (i >= 1 && candidates[i] == candidates[i-1]))
                continue;
            if(find_flag && candidates[i] == candidates[i-1])
                continue;
            if(find_flag && candidates[i] != candidates[i-1])
                find_flag = false;
            record.push_back(candidates[i]);
            int original_size = res.size();
            combinationSum2Base(candidates, i+1, target - candidates[i], record, res);
            int after_size = res.size();
            if(after_size > original_size){
                find_flag = true;
            }
            record.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
//        for(int i=0;i<candidates.size();i++){
//            cout<<candidates[i]<<", ";
//        }
        cout<<endl;
        vector<vector<int> > res;
        vector<int > record;
        combinationSum2Base(candidates, 0, target, record, res);
        return res;
    }
};
class CombinationSum{
public:
    static void test(){
        Solution solution;
        vector<int> data = {1,2,2,2,5};
        vector<vector<int> > res = solution.combinationSum2(data, 5);
        for (auto &re : res) {
            for (int j : re) {
                cout<< j <<", ";
            }
            cout<<endl;
        }
    }
};