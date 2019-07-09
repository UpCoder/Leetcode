//
// Created by Liang on 2019-07-07.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(auto i: nums){
            i = abs(i);
            nums[i-1] = -abs(nums[i-1]);
        }
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > 0){
                res.push_back(i+1);
            }
        }
        return res;
    }
    static void solution(){
        Solution solution1;
        vector<int> nums = {4,3,2,7,8,2,3,1};
        vector<int> res = solution1.findDisappearedNumbers(nums);
        for(auto i: res){
            cout<<i<<", ";
        }
        cout<<endl;
    }

};