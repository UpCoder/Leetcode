//
// Created by 梁栋 on 2019-04-27.
//
#include <string>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:

    string minWindow(string s, string t) {
        string res = "";
        vector<int > target_map(128, 0);
        int target_num = (int) t.length();
        for(int i=0;i<t.length();i++){
            target_map[t[i]] += 1;
        }
        unordered_map<char, int > source_map;
        int l = 0;
        int r = 0;
        int find_char = 0;
        while(true){
            if(l==r && r >= s.length())
                break;
            if(find_char < target_num){
                if(r >= s.length())
                    break;
                char c = s[r];
                if(target_map[c]!=0){
                    // 需要当前char
                    if(target_map[c] > source_map[c]){
                        find_char += 1;
                    }
                    source_map[c] += 1;

                }
                r += 1;
            }else{
                if(find_char == target_num){
                    string cur = s.substr(l, (r-l));
                    if(res == "" || res.length() > cur.length()){
                        res = cur;
                    }
                    char c = s[l];
                    if(source_map[c] > 0){
                        source_map[c] -= 1;
                        if(source_map[c] < target_map[c]){
                            find_char -= 1;
                        }
                    }
                    l += 1;
                }
            }
        }
        return res;
    }
    string minWindowV3(string s, string t){
        vector<int> map(128, 0);
        for(auto c: t)
            map[c] += 1;
        int l = 0, r = 0, size = (int) s.length(), len = -1, head = 0;
        int counter = (int) t.length();
        while(r < size){
            if(map[s[r]] > 0){
                counter -= 1;
            }
            map[s[r]] -= 1;
            r += 1;
            while (counter == 0){
                if(map[s[l]] == 0){
                    counter += 1;
                    if(len == -1 || (r - l) < len){
                        len = r - l;
                        head = l;
                    }
                }
                map[s[l]] += 1;
                l += 1;
            }
        }
        return len == -1 ? "": s.substr(head, len);
    }
    string minWindowV2(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) map[c]++;
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
        while(end<s.size()){
            if(map[s[end++]]-->0) counter--; //in t
            while(counter==0){ //valid
                if(end-begin<d)  d=end-(head=begin);
                if(map[s[begin++]]++==0) counter++;  //make it invalid
            }
        }
        return d==INT_MAX? "":s.substr(head, d);
    }
    static void solution(){
        Solution solution1;
        string s = "ADOBECODEBANC";
        string t = "ABC";
        cout<<solution1.minWindowV3(s, t)<<endl;

    }
};