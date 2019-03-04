//
// Created by 梁栋 on 2019-01-10.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string singleIntegerToRoman(int x, int zero_num){
        string res = "";
        char target_char = 'I';
        if(zero_num == 1){
            target_char = 'X';
        }
        if(zero_num == 2){
            target_char = 'C';
        }
        if(zero_num == 3){
            target_char = 'M';
        }
        if(x <= 3){
            if(x == 0){
                return res;
            }
            for(int i=0;i<x;i++){
                res += target_char;
            }
        }
        if(x == 4){
            if(zero_num == 0){
                res += "IV";
            }
            if(zero_num == 1){
                res += "XL";
            }
            if(zero_num == 2){
                res += "CD";
            }

        }
        if(x == 5){
            if(zero_num == 0){
                res += "V";
            }
            if(zero_num == 1){
                res += "L";
            }
            if(zero_num == 2){
                res += "D";
            }
        }
        if(x>5 && x < 9){
            if(zero_num == 0){
                res += "V";
            }
            if(zero_num == 1){
                res += "L";
            }
            if(zero_num == 2){
                res += "D";
            }
            x -= 5;
            res += singleIntegerToRoman(x, zero_num);
        }
        if(x == 9){
            if(zero_num == 0){
                res += "IX";
            }
            if(zero_num == 1){
                res += "XC";
            }
            if(zero_num == 2){
                res += "CM";
            }
        }
        return res;
    }
    string intToRoman(int num){
        string res = "";
        if(num == 0){
            return res;
        }
        if(num >= 1000){
            res += "M";
            num -= 1000;
            res += intToRoman(num);
            return res;
        }
        if(num >= 900){
            res += "CM";
            num -= 900;
            res += intToRoman(num);
            return res;
        }
        if(num >=500){
            res += "D";
            num -= 500;
            res += intToRoman(num);
            return res;
        }
        if(num >=400){
            res += "CD";
            num -= 400;
            res += intToRoman(num);
            return res;
        }
        if(num >=100){
            res += "C";
            num -= 100;
            res += intToRoman(num);
            return res;
        }
        if(num >=90){
            res += "XC";
            num -= 90;
            res += intToRoman(num);
            return res;
        }
        if(num >=50){
            res += "L";
            num -= 50;
            res += intToRoman(num);
            return res;
        }
        if(num >=40){
            res += "XL";
            num -= 40;
            res += intToRoman(num);
            return res;
        }

        if(num >=10){
            res += "X";
            num -= 10;
            res += intToRoman(num);
            return res;
        }
        if(num >=9){
            res += "IX";
            num -= 9;
            res += intToRoman(num);
            return res;
        }
        if(num >=5){
            res += "V";
            num -= 5;
            res += intToRoman(num);
            return res;
        }
        if(num >=4){
            res += "IV";
            num -= 4;
            res += intToRoman(num);
            return res;
        }
        if(num >=1){
            res += "I";
            num -= 1;
            res += intToRoman(num);
            return res;
        }
    }
    string intToRoman_v1(int num) {
        string res = "";
        int zero_num = 0;
        vector<int> numbers;
        while(num > 0){
            int cur_num = num % 10;
            numbers.push_back(cur_num);
            num /= 10;
//            cout<<num<<" | "<<numbers.size()<<endl;
        }
        for(int i=0;i<numbers.size();i++){
            int cur_num = numbers[numbers.size() - i - 1];
            string cur_presentation = singleIntegerToRoman(cur_num, numbers.size()-i-1);
//            cout<<cur_num<<" "<<cur_presentation<<endl;
            res += cur_presentation;

        }
        return res;
    }
};
class IntegerToRoman {
public:
    static void test(){
        Solution solution = Solution();
        cout<<solution.intToRoman(58)<<endl;
    }
};