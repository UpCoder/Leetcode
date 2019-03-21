//
// Created by 梁栋 on 2019-03-21.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool canJumpBase(vector<int>& nums, int start_pos){
        if(start_pos >= (nums.size()-1))
            return true;
        if(nums[start_pos] == 0)
            return false;
        for(int i=start_pos+1;i<=start_pos + nums[start_pos];i++){
            if(canJumpBase(nums, i))
                return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1)
            return true;
        int max_len = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                if((i) >= max_len)
                    return false;
            }else{
                max_len = max(max_len, i+nums[i]);
                if(max_len >= (nums.size()-1))
                    return true;
                cout<<"max_len is "<<max_len<<endl;
            }
        }
        return true;
    }
};
class JumpGame{
public:
    static void test(){
//         vector<int> nums = {3,2,1,0,4};
//        vector<int> nums = {2,3,1,1,4};
        vector<int> nums = {1,1,2,2,0,1,1};
        Solution solution;
        cout<<solution.canJump(nums)<<endl;
    }
};