//
// Created by 梁栋 on 2019-01-09.
//
#include <iostream>
#include <sstream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        // 不需要字符串的做法
        if(x<0){
            return false;
        }
        int revert_x = 0;
        int original_x = x;
        while(x>0){
            revert_x = revert_x * 10 + x % 10;
            x /= 10;
        }
//        cout<<"revert_x is "<<revert_x<<endl;
        if(revert_x == original_x){
            return true;
        }else{
            return false;
        }
    }
    bool isPalindrome1(int x) {
        if(x<0){
            return false;
        }
        stringstream ss;
        ss<<x;
        string x_str;
        ss>>x_str;
        int len = x_str.length();
        for(int i=0;i<=x_str.length()/2;i++){

            if(x_str[i] == x_str[len - i - 1]){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
};
class PalindromeNumber {
public:
    void static test(){
        int x = 10;
        Solution solution = Solution();
        bool res = solution.isPalindrome(x);
        cout<<res<<endl;
        //PINALSIGYAHRPI
        //PINALSIGYAHRPI
    }
};