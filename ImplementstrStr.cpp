//
// Created by 梁栋 on 2019-01-15.
//

#include <string>
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    int* get_next(string needle){
        int* next = new int[needle.length()];
        next[0] = -1;
        int j = 0;
        int k = -1;
        int size = needle.length();
        while(j<size - 1){
            if(k == -1 || needle[k] == needle[j]){
                j++;
                k++;
                next[j] = k;
            }else{
                k = next[k];
            }
        }
        return next;
    }
    int KMP(string haystack, string needle){
        if(needle == ""){
            return 0;
        }
        int* next = get_next(needle);
        int i=0;
        int j=0;
        while(i < int(haystack.length()) && (j < int(needle.length()))){
            // cout<<"i = "<<i<<", j = "<<j<<endl;
            if(j == -1 || haystack[i] == needle[j]){
                i++;
                j++;
            }else{
                j = next[j];
            }

        }
        if(j == needle.length()){
            return i-j;
        }else{
            return -1;
        }
    }
    int Sunday(string text, string pattern){
        map<char, int> maps;
        for(int i=0;i<pattern.length();i++){
            maps[pattern[i]] = pattern.length()-i;
        }
        map<char, int>::iterator iterator1 = maps.begin();
        int i=0;
        while(i<int(text.length())){
            int j=0;
            for(j=0;j<pattern.length();j++){
                if(text[i+j] != pattern[j]){
                    int added = maps[text[i+pattern.length()]];
                    if(added != 0){
                        i += added;
                    }else{
                        i += (pattern.length() + 1);
                    }
                    break;
                }
            }
            if(j == pattern.length()){
                return i;
            }
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        return Sunday(haystack, needle);
        // return KMP(haystack, needle);
        // return haystack.find(needle);
//        if(needle == ""){
//            return 0;
//        }
//        for(int i=0;i<haystack.length();i++){
//            if(haystack[i] == needle[0]){
//                string string1 = haystack.substr(i, needle.length());
//                if(string1 == needle){
//                    return i;
//                }
//            }
//        }
//        return -1;
    }
};
class ImplementstrStr {
public:
    static void test(){
        int x = 3;
        Solution solution = Solution();
        string haystack = "hello world";
        string needle   = "ld";
        cout<<solution.strStr(haystack, needle)<<endl;
    }
};