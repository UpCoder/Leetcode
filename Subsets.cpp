//
// Created by 梁栋 on 2019-04-28.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    void subsetsBase(vector<int>& nums, vector<vector<int>>& res, int s, vector<int>& cur){
        int last_index = -1;
        for(int i=s;i<nums.size();i++){
            if(last_index != -1 && nums[i] == nums[last_index])
                continue;
            cur.push_back(nums[i]);
            res.push_back(cur);
            subsetsBase(nums, res, i + 1, cur);
            cur.pop_back();
            last_index = i;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        res.push_back({});
        vector<int> tmp = {};
        subsetsBase(nums, res, 0, tmp);
        return res;
    }
    vector<vector<int>> subsetsWithDupV2(vector<int>& nums){
        // 集合内所有子集的个数是
        // k1 * k2 * k3 * k4, k1 k2 k3 k4 分布代表不同元素的个数
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        res.push_back({});
        int i=0;
        while(i<nums.size()){
            int count = 0;
            // 计算当前数字重复的个数
            while((i+count) < nums.size() && nums[i+count] == nums[i]){
                count += 1;
            }
            int k = (int) res.size();
            for(int j=0;j<k;j++){
                vector<int > instance = res[j]; // 遍历该数字之前的每个集合
                for(int z=0;z<count;z++){
                    //每个集合都可以加入1～count个当前元素
                    instance.push_back(nums[i]);
                    res.push_back(instance);
                }
            }
            i += count;
        }
        return res;
    }
    static void solution(){
        Solution solution1;
        vector<int> input = {4, 4, 4, 1, 4};
        vector<vector<int>> res = solution1.subsetsWithDupV2(input);
        for(auto E:res){
            cout<<"{";
            for(auto e:E){
                cout<<e<<", ";
            }
            cout<<"}"<<endl;
        }

    }
};