//
// Created by 梁栋 on 2019-01-12.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    map<char, string> number2letter = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
    };

    void letterCombinations_reclusive(string& digits, string cur_solution, int start, vector<string>& res){
        string letters = number2letter[digits[start]];
        for(int j=0;j<letters.length();j++){
            if(start == digits.length()-1){
                res.push_back(cur_solution + letters[j]);
            }else{
                letterCombinations_reclusive(digits, cur_solution + letters[j], start + 1, res);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res = vector<string>();
        letterCombinations_reclusive(digits, "", 0, res);
        return res;
    }
};
class LetterCombination{
public:
    static void print_vector(vector<string> nums){
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }

    static void test(){
        vector<int> nums = {1, 0, -1, 0, -2, 2};
        Solution solution = Solution();
        string input = "23";
        vector<string> res = solution.letterCombinations(input);
        print_vector(res);
    }
};
