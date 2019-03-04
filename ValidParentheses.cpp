//
// Created by 梁栋 on 2019-01-13.
//
#include <stack>
#include <map>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        map<char, char> map1 = {
                {']', '['},
                {'}', '{'},
                {')', '('}
        };
        stack<char> stack1 = stack<char>();
        for(int i=0;i<s.length();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stack1.push(s[i]);
            }else{
                char target = map1[s[i]];
                if(stack1.empty()){
                    return false;
                }
                char source = stack1.top();
                if(target == source){
                    stack1.pop();
                }else{
                    return false;
                }
            }
        }
        if(stack1.empty()){
            return true;
        }else{
            return false;
        }
    }
};
class ValidParentheses{
public:
    static void test(){
        string str = "(([()])){}{";
        Solution solution = Solution();
        cout<<solution.isValid(str)<<endl;
    }
};