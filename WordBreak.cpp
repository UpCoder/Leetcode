//
// Created by 梁栋 on 2019-05-06.
//
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Solution {
public:
    bool wordBreakBase(string s, vector<string>& wordDict, int idx, bool& res){
        if(s == wordDict[idx]){
            res = true;
            return true;
        }
        if(strncmp(s.c_str(), wordDict[idx].c_str(), wordDict[idx].length()) == 0){
            string tmp = s.substr(wordDict[idx].length(), s.length() - wordDict[idx].length());
            for(int i=0;i<wordDict.size();i++){
                wordBreakBase(tmp, wordDict, i, res);
                if(res)
                    return true;
            }
        }else{
            return false;
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // 利用暴力的方法来解决
        if(s == "" && wordDict.empty())
            return true;
        if(wordDict.empty())
            return false;
        if(s == "")
            return true;
        bool res = false;
        for(int i=0;i<wordDict.size();i++){
            wordBreakBase(s, wordDict, i, res);
            if(res)
                return true;
        }
        return res;
    }
    bool wordBreakDP(string s, vector<string>& wordDict){
        // 利用动态规划的思路来解决
        int len = (int) s.length();
        if(len == 0)
            return true;
        int size = (int) wordDict.size();
        if(size == 0)
            return false;
        bool dp[len]; // 每一位表示的是，以s中对应位置结束的字符在wordDict中是否存在
        // dp[i] = dp[i-word.length()] && word == s[j:i]
        memset(dp, false, sizeof(dp));
        for(int i=0;i<len;i++){
            for(int j=0;j<size;j++){
                string word = wordDict[j];
                int word_len = (int) word.length();
                if(s[i] == word[word_len - 1] &&
                ((i- word_len + 1) >= 0
                && s.substr(i-word_len+1, word_len)==word)
                && (i-word_len < 0 || dp[i-word_len])){
                    dp[i] = true;
                    break;
                }else{
                    dp[i] = false;
                }
            }
        }
        return dp[len-1];
    }
    static void solution(){
        Solution solution1;
        vector<string> wordDict = {"a", "b", "bb", "bbb", "bbbb"};
        string s = "bb";
        cout<<solution1.wordBreakDP(s, wordDict)<<endl;
    }
};
