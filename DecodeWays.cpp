//
// Created by 梁栋 on 2019-03-26.
//
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;
class Solution {
public:
    int string2int(string str){
        stringstream ss;
        ss<<str;
        int res;
        ss>>res;
        return res;
    }
    int numDecodings(string s) {
        int size = int(s.length());
        int dp[size + 1];
        memset(dp, 0, sizeof(dp));
        if(s[0] == '0')
            return 0;
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=s.length();i++){
           int first = s[i-1] - '0';
           int second = string2int(s.substr(i-2, 2));
           if(first >= 1 && first <= 9)
               dp[i] += dp[i-1];
           if(second >=10 && second <= 26)
               dp[i] += dp[i-2];
        }
        return dp[size];
    }
};
class DecodeWays{
public:
    static void test(){
        Solution solution;
        cout<<solution.numDecodings("226")<<endl;
    }
};