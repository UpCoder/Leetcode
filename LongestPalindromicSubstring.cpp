//
// Created by Liang on 2019-07-14.
//

#include <string>
#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        // 计算字符串的最长子字符串
        if(s.length() == 0)
            return "";
        string new_s = "";
        for(auto c: s){
            new_s += '#';
            new_s += c;
        }
        new_s += '#';
        int size = new_s.length();
        int mp[size]; // 代表每个点所对应的回文字符串的长度
        int idx = 0;
        int mx = 1;
        mp[0] = 1;
        cout<<new_s<<endl;
        for(int i=1;i<size;i++){
            mp[i] = i < mx ? min(mp[2 * idx - i], mx - i) : 1;
            while((i-mp[i]) >= 0 && (i + mp[i]) < size && new_s[i-mp[i]] == new_s[i + mp[i]])
                mp[i] += 1;
            if(mx < mp[i]){
                mx = i + mp[i];
                idx = i;
            }
        }
        string res = "";
        for(int i=2*idx-mx;i<=mx;i++){
            if(new_s[i] == '#')
                continue;
            res += new_s[i];
        }
        return res;
    }
    static void solution(){
        Solution solution1;
        string input_str = "cbbd";
        cout<<solution1.longestPalindrome(input_str)<<endl;
    }
};