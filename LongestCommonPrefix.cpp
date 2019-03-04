//
// Created by 梁栋 on 2019-01-10.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int pos = 0;
        string res = "";
        if(strs.size() == 0){
            return res;
        }
        if(strs.size() == 1){
            return strs[0];
        }
        while(true){
            bool equal_flag = true;
            for(int i=0;i<strs.size()-1;i++){
                if(pos<strs[i].length() && pos < strs[i+1].length() && strs[i][pos] == strs[i+1][pos]){
                    continue;
                }else{
                    equal_flag = false;
                    break;
                }
            }
            if(not equal_flag){
                break;
            }
            res += strs[0][pos];
            pos += 1;
        }
        return res;
    }
};
class LongestCommonPrefix {
public:
    static void test(){
        Solution solution = Solution();
        vector<string> strs = vector<string>();
        strs.push_back("flower");
        strs.push_back("flows");
        strs.push_back("flight");
        cout<<solution.longestCommonPrefix(strs)<<endl;
    }
};