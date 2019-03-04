//
// Created by 梁栋 on 2019-01-16.
//
#include <iostream>
using namespace std;
#define MAX 2147483647
#define MIN -2147483648
class Solution {
public:
    int divide_v2(int dividend, int divisor) {
        if((dividend == MIN && divisor == -1) || divisor == 0){
            return MAX;
        }
        return dividend / divisor;
    }
    int divide(int dividend, int divisor) {
        if((dividend == MIN && divisor == -1) || divisor == 0){
            return MAX;
        }
//        bool sign_positive = true;
//        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)){
//            sign_positive = false;
//        }
        bool sign_positive = ((dividend < 0) ^ (divisor < 0)) ? false : true;
        long long long_dividend = labs(dividend);
        long long long_divisor = labs(divisor);
        int res = 0;
        while(long_dividend >= long_divisor){
            long long tmp = long_divisor;
            int multiple = 1;
            while(long_dividend >= (tmp << 1)){
                //cout<<tmp<<", "<<multiple<<endl;
                tmp <<= 1;
                multiple <<= 1;
            }
            res += multiple;
            long_dividend -= tmp;
        }
        if(sign_positive) return res;
        return -1 * res;
    }

};
class DivideTwoIntegers{
public:
    static void test(){
        Solution solution = Solution();
        int dividend = 7;

        int divisor = -3;
        cout<<solution.divide(dividend, divisor)<<endl;
    }
};