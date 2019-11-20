//
// Created by Liang on 2019-07-27.
//
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Solution {
public:
    string countAndSayCore(string input){
        string res = "";
        int last_digit = 'A';
        int count = 0;
        for(int i=0;i<input.length();i++){
            char cur_char = input[i];
            if(last_digit == 'A'){
                last_digit = cur_char;
                count += 1;
                continue;
            }
            if(last_digit == cur_char){
                count += 1;
                continue;
            }
            res += ('0' + count);
            res += last_digit;
            last_digit = cur_char;
            count = 1;
        }
        res += ('0' + count);
        res += last_digit;
        return res;
    }
    string countAndSay(int n) {
        int x = 1;
        string res = "1";
        for(int i=1;i<n;i++){
            // cout<<"input is "<<x<<endl;
            res = countAndSayCore(res);
            // cout<<"res is "<<res<<endl;
        }
        return res;

    }
    static void solution(){
        Solution solution1;
        cout<<solution1.countAndSay(10)<<endl;
    }
};