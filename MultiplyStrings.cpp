//
// Created by 梁栋 on 2019-11-20.
//
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string add(string num1, string num2){
        if(num1.length() > num2.length()){
            return add(num2, num1);
        }
        // len(num1) < len(num2)
        string result = "";
        int jinwei = 0;
        int i=num1.length()-1;
        int j=num2.length()-1;
        for(;i >= 0 && j>=0;i--,j--){
            int a = num1[i] - '0';
            int b = num2[j] - '0';
            int c = a + b + jinwei;
            result = char('0' + (c % 10)) + result;
            jinwei = c / 10;
        }
        while(j>=0){
            int b = num2[j] - '0';
            int c = b + jinwei;
            result = char('0' + (c % 10)) + result;
            jinwei = c / 10;
            j-=1;
        }
        if(jinwei != 0){
            result = char('0' + jinwei) + result;
        }
        return result;
    }
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        string result = "0";
        for(int j=num2.length()-1;j>=0;j--){
            string tmp = "";
            int jinwei = 0;
            for(int i=num1.length()-1;i>=0;i--){
                int a = num2[j] - '0';
                int b = num1[i] - '0';
                int c = a * b + jinwei;
                tmp = char('0' + (c % 10)) + tmp;
                jinwei = c / 10;
            }
            if(jinwei!=0){
                tmp = char('0' + jinwei) + tmp;
            }
            for(int k=j;k<num2.length()-1;k++){
                tmp = tmp + '0';
            }
            result = add(result, tmp);
        }
        return result;
    }
    static void solution(){
        Solution solution1 = Solution();
        cout<<solution1.multiply("2", "3")<<endl;

    }
};