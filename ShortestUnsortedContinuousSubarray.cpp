//
// Created by Liang on 2019-07-09.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int size = nums.size();
        if(size <= 1)
            return 0;
        vector<int> copys(nums.begin(), nums.end());
        sort(copys.begin(), copys.end());
        int start = 0;
        int end = size-1;
        int res = 0;
        for(;start<size;){
            if(copys[start] != nums[start]){
                break;
            }else{
                start += 1;
            }
        }
        for(;end>start;){
            if(copys[end] != nums[end]){
                break;
            }else{
                end -= 1;
            }
        }
        res = (end - start) + 1;
        return res;
    }
    static void solution(){
         vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
//        vector<int> nums = {1,4,3,2,5};
        Solution solution1;
        cout<<solution1.findUnsortedSubarray(nums)<<endl;
    }
};