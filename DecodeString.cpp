//
// Created by Liang on 2019-06-30.
//

#include <string>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:

    bool is_number(const string s, int p){
        if('0' <= s[p] && s[p] <= '9')
            return true;
        return false;
    }
    int find_continue_number(const string s, int& i, int e){
        int res = 0;
        while(i < e && is_number(s, i)){
            res = res * 10 + (s[i] - '0');
            i += 1;
        }
        return res;
    }

    string decodeStringCore(string s, int& start, int end, int repeat){
        // s是以[开头的，repeat 代表重复的次数
        string element = "";
        // int i = start + 1;
        start += 1;
        while(start < end){
            if(is_number(s, start)){
                int sub_repeat = find_continue_number(s, start, end);
                element += decodeStringCore(s, start, end, sub_repeat);
                continue;
            }
            if(s[start] == ']'){
                start += 1;
                break;
            }
            element += s[start];
            start += 1;
        }
        string res = "";
        for(int j=0;j<repeat;j++){
            res += element;
        }
        return res;
    }
    string decodeString(string s) {
        int i=0;
        int end = s.size();


        string res = "";
        while(i < end){
            // cout<<s<<","<<i<<","<<end<<endl;
            if(is_number(s, i)){
                int sub_repeat = find_continue_number(s, i, end);
                res += decodeStringCore(s, i, s.length(), sub_repeat);
            }else{
                res += s[i];
                i += 1;
            }

        }
        return res;
    }
    static void solution(){
        Solution solution1;
        string input_str = "2[abc]3[cd]ef";
        cout<<solution1.decodeString(input_str)<<endl;
    }
};