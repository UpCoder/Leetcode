//
// Created by 梁栋 on 2019-01-17.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = int(nums.size());
        int first_decrease = -1;
        for(int j=size-1;j>0;j--){
            if(nums[j] > nums[j - 1]){
                first_decrease = j - 1;
                break;
            }
        }
        if(first_decrease == -1){
            reverse(nums.begin(), nums.end());
        } else{
            int swap_index = -1;
            for(int j = first_decrease;j<size-1;j++){
                if(nums[j + 1] <= nums[first_decrease]){
                    swap_index = j;
                    break;
                }
            }
            if(swap_index == -1){
                swap_index = size - 1;
            }
            swap(nums[first_decrease], nums[swap_index]);
            reverse(nums.begin() + first_decrease + 1, nums.end());
        }
    }
};
class NextPermutation{
public:
    static void print_vector(vector<int > nums){
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<", ";
        }
        cout<<endl;
    }
    static void test(){
        vector<int> nums = {1, 2, 3, 4, 9, 8, 7, 6, 4, 0};
        // vector<int> nums = {1, 3, 2};
        Solution solution = Solution();
        solution.nextPermutation(nums);
        print_vector(nums);
    }
};