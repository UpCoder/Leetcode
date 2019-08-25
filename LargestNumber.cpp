//
// Created by Liang on 2019-08-24.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;
namespace {
    string int2string(int x){
        stringstream ss;
        string string1;
        ss<<x;
        ss>>string1;
        return string1;
    }
    bool cmp_str(string a, string b){
        return a > b;
    }
    long long string2long(string string1){
        stringstream ss;
        long long result;
        ss<<string1;
        ss>>result;
        return result;
    }
    bool cmp(int a, int b){
        string a_str = int2string(a);
        string b_str = int2string(b);
        return cmp_str(a_str + b_str, b_str + a_str);
//        string a_str = int2string(a);
//        string b_str = int2string(b);
//        long long a_b = string2long(a_str + b_str);
//        long long b_a = string2long(b_str + a_str);
//        if(a_b > b_a)
//            return true;
//        return false;
    }
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string string1;
        if(nums.size() == 0 || nums[0] == 0)
            return "0";
        for(auto num: nums){
            string1 += int2string(num);
        }
        return string1;
    }
    static void solution(){
        vector<int> nums = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        Solution solution1;
        cout<<solution1.largestNumber(nums)<<endl;
    }
};