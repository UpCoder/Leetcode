//
// Created by 梁栋 on 2019-03-25.
//
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = int(word1.length());
        int len2 = int(word2.length());
        int dp[len1 + 1][len2 + 1];
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=len1;i++){
            dp[i][0] = i;
        }
        for(int j=1;j<=len2;j++){
            dp[0][j] = j;
        }
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j] + 1, dp[i][j-1] + 1));
                }else{
                    dp[i][j] = min(dp[i-1][j-1] + 1, min(dp[i-1][j] + 1, dp[i][j-1] + 1));
                }
            }
        }
        return dp[len1][len2];

    }
};
class EdieDistance{
public:
    static void test(){
        Solution solution;
        string word1 = "horse";
        string word2 = "ros";
        cout<<"Edit Distance is "<<solution.minDistance(word1, word2)<<endl;
    }
};
