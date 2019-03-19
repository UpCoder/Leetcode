//
// Created by 梁栋 on 2019-03-19.
//
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class Solution {
public:
    void permuteBase(const vector<int>& nums, bool* used, vector<int> cur, vector<vector<int> >& res){
        if(cur.size()==nums.size()){
            res.push_back(cur);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!used[i])
                continue;
            used[i] = false;
            cur.push_back(nums[i]);
            permuteBase(nums, used, cur, res);
            cur.pop_back();
            used[i] = true;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        int size = nums.size();
        bool used[size];
        memset(used, true, sizeof(used));
        permuteBase(nums, used, {}, res);
        return res;
    }
};
class Permutations{
public:
    static void test(){
        vector<int> nums = {1, 2, 3};
        Solution solution;
        vector<vector<int> > res = solution.permute(nums);
        cout<<"res size is "<<res.size()<<endl;
        for(int i=0;i<res.size();i++){
            for(int j=0; j<res[i].size();j++){
                cout<<res[i][j]<<", ";
            }
            cout<<endl;
        }
    }
};
