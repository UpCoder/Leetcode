//
// Created by 梁栋 on 2019-01-15.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //下面解法的空间复杂度是O(N)
//        vector<int> res = vector<int>();
//        for(int i=0;i<nums.size();i++){
//            if(nums[i] != val){
//                res.push_back(nums[i]);
//            }
//        }
//        nums = res;
//        return res.size();
        // 下面解法的空间复杂度是O(1)
        // 但是还有一个缺点就是如果nums里面val存在的较少，那么就存在大量无用的replace操作，如何优化呢？参见下一个解法
//        int end=0;
//        for(int i=0;i<nums.size();i++){
//            if(nums[i] != val){
//                nums[end] = nums[i];
//                end ++;
//            }
//        }
//        return end;
        int i = 0;
        int size = nums.size();
        while(i < size){
            if(nums[i] == val){
                // 用最后一个元素代替第i个元素
                nums[i] = nums[size - 1];
                size--;
            }else{
                i++;
            }
        }
        return size;
    }
};
class RemoveElement{
public:
    static void print(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
    static void test(){
        vector<int> nums = {0,1,2,2,3,0,4,2};
        Solution solution = Solution();
        cout<<solution.removeElement(nums, 2)<<endl;
        print(nums);
    }
};