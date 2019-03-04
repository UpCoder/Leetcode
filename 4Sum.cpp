//
// Created by 梁栋 on 2019-01-11.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> find_result(vector<int>& nums, int target, vector<vector<int>>& res, vector<int> newLists, int n, int start){
        // 代表从nums里面挑出来n个数的和等于target
        if(n < 2){
            return res;
        }
        if(n == 2){
            int front = start;
            int end = nums.size()-1;

            while(front < end){
                if((nums[front] + nums[end]) < target){
                    front += 1;
                }else{
                    if((nums[front] + nums[end]) > target){
                        end -= 1;
                    }else{
                        vector<int> solution = {nums[front], nums[end]};
                        solution.insert(solution.end(),newLists.begin(), newLists.end());
                        while(front < end && nums[front] == nums[front + 1]){
                            front += 1;
                        }
                        while(front < end && nums[end] == nums[end - 1]){
                            end -= 1;
                        }
                        res.push_back(solution);
                        front += 1;
                        end -= 1;
                    }
                }
            }
        }else{
            for(int i= start;i<nums.size();i++){
                if(i == start || nums[i] != nums[i-1]){
                //if(i == nums.size() - 1 || nums[i] != nums[i+1]){
                    newLists.push_back(nums[i]);
                    // vector<int> new_nums = vector<int>(nums.begin() + i + 1, nums.end());
                    find_result(nums, target - nums[i], res, newLists, n-1, i+1);
                    newLists.pop_back();
                }
            }
        }
        return res;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = vector<vector<int>>();
        return find_result(nums, target, res, vector<int>(), 4, 0);
    }
};
class Sum4{
public:
    static void print_vector(vector<int> nums){
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
    static void print_vector_vector(vector<vector<int>> numss){
        for(int i=0;i<numss.size();i++){
            print_vector(numss[i]);
        }
    }
    static void test(){
        vector<int> nums = {1, 0, -1, 0, -2, 2};
        Solution solution = Solution();
        vector<vector<int>> res = solution.fourSum(nums, 0);
        print_vector_vector(res);
    }
};
