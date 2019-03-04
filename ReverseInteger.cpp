//
// Created by 梁栋 on 2019-01-07.
//
#include <iostream>
#include <sstream>
using namespace std;
class Solution {
public:
    int reverse(int x){
        int res = 0;
        while(x != 0){
            if(res * 10 / 10 != res){
                return 0;
            }
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
    int reverse_v2(int x) {
        if(x == 0){
            return x;
        }
        stringstream ss;
        ss<<x;
        string x_str;
        ss>>x_str;
        string res_str = "";
        bool neg_flag = false;
        if(x_str[0] == '-'){
            neg_flag = true;
            x_str = x_str.substr(1, x_str.length()-1);
        }
        int start_pos = x_str.length()-1;
        for(;start_pos >=0; start_pos--){
            if(x_str[start_pos] != '0'){
                break;
            }
        }
        int non_zero_pos = start_pos;
        for(;start_pos>=0;start_pos--){
            res_str += x_str[start_pos];
        }
//        cout<<"res_str is "<<res_str<<endl;
        stringstream sss;
        sss<<res_str;
        long long int res;
        sss>>res;
//        cout<<"res is "<<res<<endl;
        if(neg_flag){
            res *= -1;
        }
        int boundary = 1 << 31;
        if(res > boundary-1 or res < -boundary){
            return 0;
        }
        return res;
    }
};
class ReverseInteger {
public:
    void static test(){
        int x = -1234;
        Solution solution = Solution();
        int res = solution.reverse(x);
        cout<<res<<endl;
        //PINALSIGYAHRPI
        //PINALSIGYAHRPI
    }
};