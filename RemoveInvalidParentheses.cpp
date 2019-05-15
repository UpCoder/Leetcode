//
// Created by 梁栋 on 2019-05-15.
//

#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include <set>
using namespace std;
class Solution {
public:
    int deleteCharFrom(string s, char target, int pos, int step=1){
        int len = s.length();
        int i=pos;
        for(;i>=0 && i<len;i += step){
            if(s[i] == target){
                continue;
            }
            break;
        }
        return i;
    }
    int countNumInvalidParenthess(string string1){
        int num_left = 0;
        int num_invalid = 0;
        for(int i=0;i<string1.length();i++){
            char c = string1[i];
            if(c != '(' && c != ')')
                continue;
            if(c == '('){
                num_left += 1;
            }
            else{
                if(num_left > 0){
                    num_left -= 1;
                }else{
                    num_invalid += 1;
                }
            }
        }
        num_invalid += num_left;
        return num_invalid;
    }
    string replaceNonParenthese(string string1){
        string res = "";
        for(int i=0;i<string1.length();i++){
            if(string1[i] == '(' || string1[i] == ')')
                res += string1[i];
        }
        return res;
    }
    string isValid(string s, bool* valid){
        int num_left = 0;
        int len = s.length();
        string res = "";
        for(int i=0;i<len;i++){
            if(s[i] != '(' && s[i] != ')'){
                res += s[i];
                continue;
            }
            if(valid[i]){
                if(s[i] == '('){
                    num_left += 1;
                }else{
                    if(num_left >= 1){
                        num_left -= 1;
                    }else{
                        return "NULL";
                    }
                }
                res += s[i];
            }
        }
        if(num_left != 0)
            return "NULL";
        return res;
    }
    void removeInvalidParentheses(string s, bool* valid, set<string>& res, int needNumInvalid, int start_pos=0){
        if(needNumInvalid == 0){
            string string1 = isValid(s, valid);
            if(string1 != "NULL"){
                res.insert(string1);
            }
            return;
        }
        for(int i=start_pos;i<s.length();i++){
            if(s[i] != '(' && s[i] != ')')
                continue;
            valid[i] = false;
            removeInvalidParentheses(s, valid, res, needNumInvalid-1, i + 1);
            valid[i] = true;
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        set<string> res_set;
        int left = deleteCharFrom(s, ')', 0, 1);
        s = s.substr(left);
        int right = deleteCharFrom(s, '(', s.length()-1, -1);
        s = s.substr(0, right + 1);
        // s = replaceNonParenthese(s);
        int num_invalid = countNumInvalidParenthess(s);
        bool* valid = new bool[s.length()];
        memset(valid, true, sizeof(bool) * s.length());
        cout<<s<<", "<<num_invalid<<endl;
        removeInvalidParentheses(s, valid, res_set, num_invalid);
        vector<string> res(res_set.size());
        copy(res_set.begin(), res_set.end(), res.begin());
        return res;
    }
    bool isValid(string s){
        int num_left = 0;
        int len = s.length();
        for(int i=0;i<len;i++){
            if(s[i] != '(' && s[i] != ')'){
                continue;
            }
            if(s[i] == '('){
                num_left += 1;
            }else{
                if(num_left >= 1){
                    num_left -= 1;
                }else{
                    return false;
                }
            }
        }
        return num_left == 0;
    }
    vector<string> filter(set<string> set1){
        vector<string> res;
        for(auto s: set1){
            if(isValid(s)){
                res.push_back(s);
            }
        }
        return res;
    }
    vector<string> removeInvalidParenthesesV2(string str) {
        set<string> set1;
        set1.insert(str);
        while(true){
            vector<string> res = filter(set1);
            if(res.size() > 0)
                return res;
            set<string> set2;
            for(auto s:set1){
                for(int i=0;i<s.length();i++){
                    string temp = s.substr(0, i) + s.substr(i+1);
                    set2.insert(temp);
                    // cout<<temp<<", "<<set2.size()<<endl;
                }
            }
            set1 = set2;
        }
    }
    static void solution(){
        Solution solution1;
        string input = "()(";
        vector<string> res = solution1.removeInvalidParenthesesV2(input);
        for(auto c: res){
            cout<<c<<endl;
        }
    }
};