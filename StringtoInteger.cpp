//
// Created by 梁栋 on 2019-01-08.
//
#include <iostream>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int non_space_idx = 0;
        for(;non_space_idx<str.length();non_space_idx++){
            if(str[non_space_idx] == ' '){
                continue;
            }else{
                break;
            }
        }
        str = str.substr(non_space_idx, str.length()-non_space_idx);
        if((str[0] != '-' && str[0] != '+') && (str[0] < '0' || str[0] > '9')){
            return 0;
        }
        bool neg_flag = false;
        bool pos_flag = true;
        // 判断第一个字符是不是+，如果是，则第二个字符必须是数字
        if(str[0] == '+'){
            pos_flag = true;
            str = str.substr(1, str.length()-1);
            if(str[0] < '0' || str[0] > '9'){
                return 0;
            }
        }
        //判断第一个字符是不是-，如果是则第二个字符必须是数字
        if(str[0] == '-'){
            neg_flag = true;
            str = str.substr(1, str.length()-1);
            if(str[0] < '0' || str[0] > '9'){
                return 0;
            }
        }
        int idx = 0;
        int res = 0;
        bool outrange = false;
        while(str[idx] >= '0' && str[idx] <= '9'){
            int cur_number = str[idx] - '0';
            // 判断有没有越界
            if(res * 10 / 10 != res){
                outrange = true;
                break;
            }
            res = res * 10 + cur_number;
            //判断有没有越界
            if(res < 0){
                outrange = true;
                break;
            }
            idx += 1;

        }
        if(outrange){
            if(neg_flag){
                res = 1<<31;
                res *= -1;
            }else{
                res = 1<<31;
                res -= 1;
            }
        }else{
            if(neg_flag){
                res *= -1;
            }
        }
        return res;
    }
};
class StringtoInteger {
public:
    void static test(){
//        string s = "2147483646"; //2147483646
        string s = "2147483648"; // 2147483647
        Solution solution = Solution();
        int res = solution.myAtoi(s);

        cout<<res<<endl;
        //PINALSIGYAHRPI
        //PINALSIGYAHRPI
    }
};