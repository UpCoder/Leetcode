//
// Created by 梁栋 on 2019-05-16.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_idx = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                zero_idx = i;
                break;
            }
        }
        if(zero_idx == -1)
            return;
        int non_zero_idx = zero_idx + 1;
        int size = (int) nums.size();
        while(non_zero_idx < size && zero_idx < size){
            while(non_zero_idx < size){
                if(nums[non_zero_idx] == 0){
                    non_zero_idx += 1;
                }else{
                    break;
                }
            }
            if(non_zero_idx >= size)
                break;
            swap(nums[non_zero_idx], nums[zero_idx]);
            zero_idx += 1;
            non_zero_idx += 1;
        }
    }
};