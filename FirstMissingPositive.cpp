//
// Created by Liang on 2019-07-27.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        if(size == 0){
            return 1;
        }
        int start = 0;
        while(start < size){
            if(nums[start] == (start + 1)){
                start += 1;
                continue;
            }
            if(nums[start] <= 0 || nums[start] > size){
                start += 1;
                continue;
            }
            if(nums[nums[start]-1] == nums[start]){
                start += 1;
                continue;
            }
            swap(nums[start], nums[nums[start]-1]);
        }
        for(int i=0;i<size;i++){
            if(nums[i] != (i+1))
                return i+1;
        }
        return size+1;
    }
    static void solution(){
        vector<int> input = {0, 1, 1, 2, 2};
        Solution solution1;
        cout<<solution1.firstMissingPositive(input)<<endl;
    }
};