//
// Created by 梁栋 on 2019-01-11.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int compute_interval(int a, int b, int c, int target){
        return abs(a + b + c - target);
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        int interval = abs(nums[0] + nums[1] + nums[2] - target);
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            int cur_target = target - nums[i];
            int front = i + 1;
            int end = nums.size() - 1;
            while(front < end){
                if((nums[front] + nums[end]) < cur_target){

                    int cur_interval = compute_interval(nums[front], nums[end], nums[i], target);
                    if(cur_interval < interval){
                        interval = cur_interval;
                        res = nums[front] + nums[end] + nums[i];
                    }
                    front += 1;
                    continue;
                }
                if((nums[front] + nums[end]) > cur_target){

                    int cur_interval = compute_interval(nums[front], nums[end], nums[i], target);
                    if(cur_interval < interval){
                        interval = cur_interval;
                        res = nums[front] + nums[end] + nums[i];
                    }
                    end -= 1;
                    continue;
                }
                if((nums[front] + nums[end]) == cur_target){
                    res = nums[front] + nums[end] + nums[i];
                    return res;
                }
            }
            while(i < nums.size() - 1 && nums[i] == nums[i+1]){
                i++;
            }
        }
        return res;
    }
};
class Sum3Closest {
public:

    static void test(){

        vector<int> nums = {-1, 2, 1, -4};
        Solution solution = Solution();
        int res = solution.threeSumClosest(nums, 1);
        cout<<res<<endl;

    }
};