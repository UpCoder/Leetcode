//
// Created by 梁栋 on 2019-01-13.
//
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
class Solution {
public:
    void print_stack(stack<char> stack1){
        while(not stack1.empty()){
            cout<<stack1.top();
            stack1.pop();
        }
        cout<<endl;
    }
    void generate(int n, vector<string>& res, string s="(", int i=1){
        // n represent the number of the pair of we need to add '()'
        // i represent the number of exisisting of (
        if(n == 0){
            res.push_back(s);
        }
        if(i<n){
            generate(n, res, s + "(", i + 1);
        }
        if(i > 0){
            generate(n-1, res, s + ")", i-1);
        }
    }
    void sub(int n, vector<string>& res, stack<char>& stack1, string str){
        if(stack1.size() > n){
            return;
        }
        // cout<<"str is "<<str<<endl;
        // print_stack(stack1);
        if(n == 1){
            if(stack1.empty() || stack1.top() != '('){
                // stack1.pop();
                return;
            }else{
                str += ")";
                // stack1.pop();
                if(stack1.size() == 1){
                    // cout<<"push_back str is "<<str<<endl;
                    res.push_back(str);
                }
                str = str.substr(0, str.length()-1);
                return;
            }
        }
        stack1.push('(');
        str += "(";
        sub(n-1, res, stack1, str);
        stack1.pop();
        str = str.substr(0, str.length()-1);
        if(not stack1.empty()){
            str += ")";
            stack1.pop();
            sub(n-1, res, stack1, str);
            str = str.substr(0, str.length()-1);
            stack1.push('(');
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res = vector<string>();
        stack<char> stack1 = stack<char>();
//        string cur_solution = "";
//        sub(n * 2, res, stack1, cur_solution);
        generate(n, res);
        return res;
    }
};
class GenerateParentheses{
public:
    static void print_vector(vector<string > nums){
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<endl;
        }
        cout<<endl;
    }
    static void test(){
        int n = 3;
        Solution solution = Solution();
        vector<string> res = solution.generateParenthesis(n);
        print_vector(res);
    }
};