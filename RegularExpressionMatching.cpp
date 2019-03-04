//
// Created by 梁栋 on 2019-01-09.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool equal_char(char x, char y){
        if(x == y || y == '.'){
            return true;
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool> > dp(m + 1, vector<bool> (n + 1, false));
        dp[0][0] = true;
        for(int i=0;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1] != '*' && i>0){
                    dp[i][j] = dp[i-1][j-1] && equal_char(s[i-1], p[j-1]);
                }
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2] || (i>0 && dp[i-1][j] && equal_char(s[i-1], p[j-2]));
                }
            }
        }
        return dp[m][n];
    }
    bool isMatch1(string s, string p) {
        // 主要思路是递归，判断第一个字符是否相等，如果相等继续比较下一个，否则返回false，终止条件是字符串长度为空
        if(s.length() == 0 && p.length() == 0){
            return true;
        }
        if(s.length() !=0 && p.length() == 0){
            return false;
        }
        if(s.length() == 0 && p.length() != 0){
            if(p.length() >= 2 && p[1] == '*'){
                return isMatch(s, p.substr(2));
            }
            return false;
        }
        // 如果第二个字符不是*，则比较简单
        if((p.length() > 1 && p[1] != '*') || p.length() == 1){
            if(equal_char(s[0], p[0])){
                return isMatch(s.substr(1), p.substr(1));
            }else{
                return false;
            }
        }
        // 如果第二个字符是*
        if(p.length() > 1 && p[1] == '*'){
            while(s.length() > 0 && equal_char(s[0], p[0])){
                // 循环次数加一，则*匹配的次数加一
                // 之所以要在while循环里加isMatch是因为有时候匹配的个数取决于s和p，并不是简单的能匹配多少就匹配多少
                // 比如说S='ABCC', P='.*C' 和 P='.*CC'都可以匹配成功
                if(isMatch(s, p.substr(2))){
                    return true;
                }
                s = s.substr(1);    //个数加1
            }
            // 不相等的话，直接跳过，当成0个
            return isMatch(s, p.substr(2));
        }

    }
};
class RegularExpressMatching {
public:
    void static test(){
        string s = "abcc";
        string p = ".*c";
        Solution solution = Solution();
        bool res = solution.isMatch(s, p);
        cout<<res<<endl;
        //PINALSIGYAHRPI
        //PINALSIGYAHRPI
    }
};