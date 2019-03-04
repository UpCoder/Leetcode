//
// Created by 梁栋 on 2019-01-18.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int binary_find(vector<int>& nums, int l, int r, int target){
        if(l==r){
            if(nums[l] == target){
                return l;
            }else{
                return -1;
            }
        }
        int mid = (l + r) / 2;
        int left_res = binary_find(nums, l, mid, target);
        return left_res == -1 ? binary_find(nums, mid + 1, r, target) : left_res;

    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==0){
            return -1;
        }
        return binary_find(nums, 0, nums.size()-1, target);
    }
};
class SearchRotatedSortedArray{
public:
    static void test(){
        vector<int> nums = {4,5,6,7,0,1,2};
        int target = 3;
        Solution solution = Solution();
        cout<<solution.search(nums, target)<<endl;
    }
};