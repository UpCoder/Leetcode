//
// Created by 梁栋 on 2019-03-18.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void combinationSumBase(const vector<int>& candidates, int start, int target, vector<int > record, vector<vector<int> >& res){
        if(target == 0){
            res.push_back(record);
            return ;
        }
        for(int i=start;i<candidates.size() && target >= candidates[i];i++){
            record.push_back(candidates[i]);
            combinationSumBase(candidates, i, target - candidates[i], record, res);
            record.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int > record;
        combinationSumBase(candidates, 0, target, record, res);
        return res;
    }
};
class CombinationSum{
public:
    static void test(){
        Solution solution;
        vector<int> data = {2, 3, 5};
        vector<vector<int> > res = solution.combinationSum(data, 8);
        for(int i=0;i<res.size();i++){
            for(int j=0;j<res[i].size();j++){
                cout<<res[i][j]<<", ";
            }
            cout<<endl;
        }
    }
};