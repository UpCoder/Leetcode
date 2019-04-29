//
// Created by 梁栋 on 2019-04-26.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // 0所在的范围应该是[0, b), 1 should be in [b, a), 2 should be in (a, end]
        int a = 0;  // count 1
        int b = 0;  // count 0
        for(int i=0;i<nums.size();i++){
            v = nums[i];
            nums[i] = 2;
            if(v < 2){
                nums[a] = 1;
                a += 1;
            }
            if(v == 0){
                nums[b] = 0;
                b += 1;
            }
        }
    }
};