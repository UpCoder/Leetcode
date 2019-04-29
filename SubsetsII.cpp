//
// Created by 梁栋 on 2019-04-28.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void subsetsBase(vector<int>& nums, vector<vector<int>>& res, int s, vector<int> cur){
        for(int i=s;i<nums.size();i++){
            
            cur.push_back(nums[i]);
            res.push_back(cur);
            subsetsBase(nums, res, i + 1, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        subsetsBase(nums, res, 0, {});
        return res;
    }
    static void solution(){
        Solution solution1;
        vector<int> input = {1, 2, 2};
        vector<vector<int>> res = solution1.subsets(input);
        for(auto E:res){
            cout<<"{";
            for(auto e:E){
                cout<<e<<", ";
            }
            cout<<"}"<<endl;
        }

    }
};