//
// Created by 梁栋 on 2019-05-16.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> l2r;
        vector<int> r2l;
        l2r.push_back(1);
        for(int i=1;i<nums.size();i++){
            l2r.push_back(nums[i-1] * l2r.back());
        }
        int size = (int) nums.size();
        r2l.push_back(1);

        for(int i=size-2;i>=0;i--){
            r2l.push_back(nums[i+1] * r2l.back());
        }
        vector<int> res;
        for(int i=0;i<size;i++){
            res.push_back(l2r[i] * r2l[size-i-1]);
        }
        return res;
    }
    vector<int> productExceptSelfV2(vector<int>& nums) {
        vector<int> res;
        int p = 1;
        for(auto c: nums){
            res.push_back(p);
            p *= c;
        }
        p = 1;
        int size = (int) nums.size();
        for(int i=size-1;i>=0;i--){
            res[i] = res[i] * p;
            p *= nums[i];
        }
        return res;
    }
    static void solution(){
        Solution solution1;
        vector<int> input = {1, 0, 2, 3, 4, 5};
        vector<int> res = solution1.productExceptSelfV2(input);
        for(auto c: res){
            cout<<c<<", ";
        }
        cout<<endl;
    }
};