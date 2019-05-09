//
// Created by 梁栋 on 2019-05-06.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int x = nums[0];
        for(int i=1;i<nums.size();i++){
            x = x ^ nums[i];
        }
        return x;
    }
    static void solution(){
        Solution solution1;
        vector<int> nums = {2, 2, -1, -1, 1, 4, 1, 4, 2, 0, 2};
        cout<<solution1.singleNumber(nums)<<endl;
    }
};