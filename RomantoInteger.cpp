//
// Created by 梁栋 on 2019-01-10.
//
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        map<string, int> romanInt{
                {"I", 1},
                {"IV", 4},
                {"V", 5},
                {"IX", 9},
                {"X", 10},
                {"XL", 40},
                {"L", 50},
                {"XC", 90},
                {"C", 100},
                {"CD", 400},
                {"D", 500},
                {"CM", 900},
                {"M", 1000},
        };
        int res = 0;
        while(s.length()>0){
            bool find_flag = false;
            if(s.length() >= 2){
                for(map<string, int>::iterator iterator1=romanInt.begin();iterator1 != romanInt.end(); iterator1++){
                    if(s.substr(0, 2) == iterator1->first){
                        res += iterator1->second;
                        s = s.substr(2);
                        find_flag=true;
                        break;
                    }
                }
            }
            if(find_flag){
                continue;
            }
            for(map<string, int>::iterator iterator1=romanInt.begin();iterator1 != romanInt.end(); iterator1++){
                if(s.substr(0, 1) == iterator1->first){
                    res += iterator1->second;
                    s = s.substr(1);
                    break;
                }
            }
        }
        return res;
    }
};
class RomantoInteger {
public:
    static void test(){
        Solution solution = Solution();
        cout<<solution.romanToInt("LVIII")<<endl;
    }
};