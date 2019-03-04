//
// Created by 梁栋 on 2019-01-15.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int end = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[end] != nums[i]) {
                end += 1;
                nums[end] = nums[i];
            }
        }
        // nums = vector<int>(nums.begin(), nums.begin()+end);
        return end + 1;
    }
};
class RemoveDuplicatesfromSortedArray{
public:
    static void print(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
    static void test(){
        vector<int> nums = {1, 1, 1, 2, 2, 3, 3, 6, 6, 8};
        Solution solution = Solution();
        cout<<solution.removeDuplicates(nums)<<endl;
        print(nums);
    }
};