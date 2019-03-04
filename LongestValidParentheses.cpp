//
// Created by 梁栋 on 2019-01-17.
//
#include <string>
#include <cstring>
#include <string.h>
#include <memory.h>
#include <iostream>
#include <stack>
#include <map>
using namespace std;
template < typename T > void print( const std::stack<T>& stk )
{
    struct cheat : std::stack<T> { using std::stack<T>::c ; } ;
    const auto& seq = static_cast< const cheat& >(stk).c ;

    for( const auto& v : seq ) std::cout << v << ' ' ;
    std::cout << '\n' ;
}
class Solution {
public:
    int get_res_from_stack(stack<int> stack2){
        int res = 0;
        bool restart = false;
        int cur_res = 0;
        // print(stack2);
        while(not stack2.empty()){
            int cur = stack2.top();
            stack2.pop();
            if(cur == 1){
                restart = true;
            }
            if(cur == 2){
                if(restart){
                    cur_res = 2;
                    restart = false;

                }else{
                    cur_res += 2;
                }
                res = max(res, cur_res);
            }
        }
        return res;
    }

    int get_res_from_map(map<int, int> map1){
        map<int, int>::iterator iterator1 = map1.begin();
        bool restart = false;
        int res = 0;
        int cur_res = 0;
        while(iterator1 != map1.end()){
            int value = iterator1->second;
            if(value == 1){
                restart = true;
            }
            if(value == 2){
                if(restart){
                    cur_res = 2;
                    restart = false;
                }else{
                    cur_res += 2;
                }
                res = max(res, cur_res);
            }
            iterator1 ++;
        }
        return res / 2;
    }
    int longestValidParentheses_v2(string s) {
        // cout<<s<<endl;
        stack<char> stack1;
        stack<int> stack2;
        int res = 0;
        int cur_len = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == ')'){
                if(stack1.empty()){
                    return max(max(res, get_res_from_stack(stack2)), longestValidParentheses(s.substr(i+1)));
                }else{
                    cur_len += 2;
                    stack1.pop();
                    // cout<<stack2.top()<<endl;
                    stack<int> tmp;
                    while(stack2.top() != 1){
                        tmp.push(stack2.top());
                        stack2.pop();
                    }
                    stack2.pop();
                    stack2.push(2);
                    while(not tmp.empty()){
                        stack2.push(tmp.top());
                        tmp.pop();
                    }
                }
            }else{
                stack1.push('(');
                stack2.push(1);
            }
        }
        res = max(res, get_res_from_stack(stack2));
        return res;
    }
    int longestValidParentheses_v1(string s){
        stack<int > stack1;
        stack1.push(-1);
        int res = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                stack1.push(i);
            }else{
                stack1.pop();
                if(stack1.empty()){
                    stack1.push(i);
                }else{
                    int len = i - stack1.top();
                    res = max(res, len);
                }
            }
        }
        return res;
    }
    int longestValidParentheses(string s) {
        // cout<<s<<endl;
        stack<int> stack2;
        map<int, int> map1;
        int res = 0;
        int cur_len = 0;
        for(int i=0;i<s.length();i++){
            map1[i] = 1;
            if(s[i] == ')'){
                if(stack2.empty()){
                    stack2 = stack<int >();
                }else{
                    cur_len += 2;
                    int pos = stack2.top();
                    stack2.pop();
                    map1[pos] = 2;
                    map1[i] = 2;
                }
            }else{
                stack2.push(i);
            }
        }
        return get_res_from_map(map1);
    }
    int longestValidParentheses_v3(string s){
        // dp
        int* dp = new int[s.length()];
        memset(dp, 0, sizeof(int) * s.length());
        int res = 0;
        for(int i=1;i<s.length();i++){
            if(s[i] == ')' && s[i-1] == '('){
                if(i>=2)
                    dp[i] = dp[i-2] + 2;
                else
                    dp[i] = 2;
            }else{
                if(s[i] == ')' && s[i-1] == ')'){
                    if(s[i-dp[i-1]-1] == '('){
                        dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2];
                    }
                }
            }
            res = max(res, dp[i]);
            // cout<<"i="<<i<<", dp="<<dp[i]<<endl;
        }
        return res;
    }
    int longestValidParentheses_v4(string s){
        stack<int > stack1;
        bool restart = false;
        // stack1.push(-1);
        int res = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                stack1.push(i);
            }else{
                if(stack1.empty()){
                    return max(res, longestValidParentheses_v4(s.substr(i+1)));
                }
                int len = i - stack1.top() + 1;
                res = max(res, len);
                stack1.pop();

            }
        }
        return res;
    }
};
class LongestValidParentheses{
public:
    static void test(){
        // string s = "(()(((()"; // 2
        // string s = "(()"; // 2
        // string s = ")()())"; // 4
        string s = "()(())"; // 6
        Solution solution = Solution();
        cout<<solution.longestValidParentheses_v4(s)<<endl;
    }
};