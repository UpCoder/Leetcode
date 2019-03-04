//
// Created by 梁栋 on 2019-01-18.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void binary_find(vector<int>& nums, int l, int r, int target, int& l_est, int& r_est){
        if(l == r){
            if(nums[l] == target){
                if(l_est == -1){
                    l_est = l;
                    r_est = l;
                    return;
                }
                l_est = min(l_est, l);
                r_est = max(r_est, l);

            }
            return ;
        }
        int mid = (l + r) / 2;
        binary_find(nums, l, mid, target, l_est, r_est);
        binary_find(nums, mid + 1, r, target, l_est, r_est);

    }
    vector<int> searchRange(vector<int>& nums, int target) {
//        int l_est = -1;
//        int r_est = -1;
//        if(nums.size()!=0)
//            binary_find(nums, 0, nums.size()-1, target, l_est, r_est);
//        vector<int> res = {l_est, r_est};
//        return res;

        vector<int> res = {
                binary_find(nums, target, true),
                binary_find(nums,target, false)
        };
        return res;
    }

    int binary_find(vector<int>& nums, int target, bool is_left){
        // 返回最左边或者是最右边的值
        if(nums.empty()){
            return -1;
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
};
class FindFirstLastPositionElementSortedArray{
public:
    static void print_vector(vector<int > res){
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<", ";
        }
        cout<<endl;
    }
    static void test(){
        vector<int> nums = {5,7,7,8,8,10};
        int target = 8;
        Solution solution = Solution();
        print_vector(solution.searchRange(nums, target));

    }
};