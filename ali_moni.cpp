//
// Created by Liang on 2019-08-26.
//

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution{
public:
    int find_in_string(string str, char target, int start){
        for(int i=start;i<str.length();i++){
            if(str[i] == target)
                return i;
        }
        return -1;
    }
    bool is_matching(string pattern, string input, int pattern_idx, int input_idx){

        for(int i=pattern_idx;i<pattern.length();){
            if(pattern[i] == '<'){
                is_matching(pattern, input, i + 1, input_idx);
                continue;
            }
            if(pattern[i] == '['){

            }
        }
    }
};