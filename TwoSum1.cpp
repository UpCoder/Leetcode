//
// Created by 梁栋 on 2018-12-16.
//
#include <iostream>
#include <map>
#include <vector>
#include "./utils.cpp"
using namespace std;

class Solution1 {
public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        vector<int> res = vector<int>();
//        unsigned long size = nums.size();
//        for(int i=0;i<size; i++){
//            for(int j=0;j<size;j++){
//                if(i == j){
//                    continue;
//                }
//                if((nums[i] + nums[j]) == target){
//                    res.push_back(i);
//                    res.push_back(j);
//                    return res;
//                }
//            }
//        }
//    }
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> myRecord = map<int, int>();
        vector<int> res = vector<int>();
        for(int i=0;i<nums.size();i++)
        {
            myRecord[nums[i]] = i+1;
        }
        for(int i=0;i<nums.size();i++)
        {
            // myRecord[target - nums[i]] != (i+1) 是避免出现3+3=6的情况，保证一个数字只能用一次。也就是剩下的数不能再是现在这个
            if(myRecord[target - nums[i]] != 0 && myRecord[target - nums[i]] != (i+1))
            {
                res.push_back(i);
                res.push_back( myRecord[target - nums[i]]-1);
                break;
            }
        }
        return res;
    }
};
class TwoSum1 {
public:
    static void test(){
        vector<int> nums = vector<int>();
        nums.push_back(2);
        nums.push_back(7);
        nums.push_back(11);
        nums.push_back(15);
        Solution1 solution = Solution1();
        int target = 9;
        vector<int> res = solution.twoSum(nums, target);
        Utils::print_vector(res);
    }
};

