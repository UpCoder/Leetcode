//
// Created by 梁栋 on 2019-01-18.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int binary_find(vector<int>& nums, int target, bool is_left){
        // 返回最左边或者是最右边的值
        if(nums.empty()){
            return 0;
        }
        int l = 0;
        int r = nums.size()-1;
        int res = -1;
        while(l < r || (l == r && r < nums.size())){
            int mid = (l + r) / 2;
            if(nums[mid] == target){
                res = mid;
                if(is_left){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
            if(nums[mid] > target){
                r = mid - 1;
            }
            if(nums[mid] < target){
                l = mid + 1;
            }
        }
        return res;
    }
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=target){
                return i;
            }
        }
        return nums.size();
    }
};