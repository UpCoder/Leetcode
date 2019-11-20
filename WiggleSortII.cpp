//
// Created by Liang on 2019-09-02.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        int mid = nums.size() % 2 == 0 ? nums.size() / 2 : nums.size() / 2 + 1;
        mid = mid - 1;
        int l = mid;
        int r = nums.size()-1;
        while(l >= 0 && r > mid){
            tmp.push_back(nums[l]);
            l--;
            tmp.push_back(nums[r]);
            r--;
        }
        if(l>=0){
            tmp.push_back(nums[l]);
        }
        for(int i=0;i<nums.size();i++){
            nums[i] = tmp[i];
        }
    }
    static void solution(){
        vector<int> nums = {1, 5, 1, 1, 6, 4};
        Solution solution1;
        solution1.wiggleSort(nums);
        for(auto num: nums){
            cout<<num<<" ";
        }
//        [1,3,2,2,3,1]
        cout<<endl;
    }
};
//1, find the middle element "firstlast", by using nth_element() function,
//2, get all the elements less than middle element "firstlast" into the odd positions,
//3, get all the elements greater than middle element "firstlast" into the even positions,
//4, in all the odd positions, swap all elements that equal to "firstlast" to the left,
//5, in all the even positions, swap all elements that equal to "firstlast" to the right.