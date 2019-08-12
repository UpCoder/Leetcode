//
// Created by Liang on 2019-07-11.
//
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int countSubstringsCoreV2(string s){
        int size = s.size();
        if(size <= 1)
            return size;
        int res = 0;
        for(int center=0;center<size*2-1;center++){
            int left = center / 2;  // 每个两次会重复，一次代表长度是奇数，一次代表长度是偶数。如果center%2!=0,则代表长度是奇数
            int right = left + center % 2;  // 一次是奇数，一次是偶数
            while(left >=0 && right < size && s[left] == s[right]){
                res += 1;
                left --;
                right ++;
            }
        }
        return res;
    }
    int countSubstringsCoreV1(string s){
        // O(N^3)
        int size = s.size();
        if(size <= 1)
            return size;
        int res = 0;
        for(int i=0;i<size;i++){
            res += 1;
            for(int j=i+1;j<size;j++){
                bool is_flag = true;
                for(int k=0;k<(j-i);k++){
                    if(s[i+k] != s[j-k]){
                        is_flag = false;
                        break;
                    }
                }
                if(is_flag){
                    res += 1;
                }
            }
        }
        return res;
    }
    int countSubstrings(string s) {
        return countSubstringsCoreV2(s);
    }
    static void solution(){
        Solution solution1;
        string s = "aaa";
        cout<<solution1.countSubstrings(s)<<endl;
    }
};