//
// Created by 梁栋 on 2019-05-05.
//
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        unordered_map<int, int> unordered_map1;
        for(auto c: nums){
            unordered_map1[c] += 1;
        }
        int len = -1;
        for(auto c: nums){
            int cur_len = 1;
            if(unordered_map1[c]==0)
                continue;
            bool left_flag = true;
            bool right_flag = true;
            int step = 1;
            while(right_flag || left_flag){
                long long left_c = c - step;
                long long right_c = c + step;
                if(left_flag && unordered_map1[left_c] >= 1){
                    cur_len += 1;
                    unordered_map1[left_c] = 0;
                }else{
                    left_flag = false;
                }
                if(right_flag && unordered_map1[right_c] >= 1){
                    cur_len += 1;
                    unordered_map1[right_c] = 0;
                }else{
                    right_flag = false;
                }
                step += 1;
            }
            len = max(len, cur_len);
        }
        return len;
    }
    static void solution(){
        vector<int> nums = {2147483646, -2147483647, 0, 2, 2147483644, -2147483645, 2147483645};
        Solution solution1;
        cout<<solution1.longestConsecutive(nums)<<endl;
    }
};