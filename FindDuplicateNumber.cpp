//
// Created by 梁栋 on 2019-05-16.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++)
                if(nums[i] == nums[j])
                    return nums[i];
        }
        return -1;
    }
    int findDuplicateV2(vector<int>& nums){
        int size = (int) nums.size();
        if(size > 1){
            int slow = nums[0];
            int fast = nums[nums[0]];
            while(slow != fast){
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            slow = 0;
            while(slow != fast){
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
        }
        return -1;
    }
    int findDuplicateV3(vector<int>& nums){
        int size = (int) nums.size();
        if(size > 1){
            int leftCount = 0;
            int rightCount = 0;
            int left = 1;
            int right = size - 1;
            while(left < right){
                int mid = (right + left) / 2; //
                int count = 0;
                for(auto c: nums){
                    if(c <= mid){
                        count += 1;
                    }
                }
                if(count > mid){
                    right = mid;
                }else{
                    left = mid + 1;
                }
            }
            return left;
        }
        return -1;
    }
    static void solution(){
        Solution solution1;
        vector<int> nums = {1, 3, 4, 2, 2};
        cout<<solution1.findDuplicateV3(nums)<<endl;
    }
};
