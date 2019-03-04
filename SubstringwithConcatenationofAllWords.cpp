//
// Created by 梁栋 on 2019-01-16.
//
#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
//    int canbe_used_in_words(string s, vector<string>& words, map<int, int>& used){
//        for(int i=0;i<words.size();i++){
//            if(used[i] == 0 && s == words[i]){
//                return i;
//            }
//        }
//        return -1;
//    }
//    void generate(string s, int l, vector<string>& words, map<int, int>& used_ids, int& word_length, vector<int>& res, int count){
//        if(count == words.size()){
//            res.push_back(l - count * word_length);
//            return;
//        }
//        int start_pos = l + int(used_ids.size() * word_length);
//        for(int i=start_pos;i<s.length();i+=word_length){
//            string cur_str = s.substr(i, word_length);
//            int index = canbe_used_in_words(cur_str, words, used_ids);
//            if(index == -1){
//                used_ids = map<int, int >();
//                count = 0;
//                continue;
//            }else{
//                used_ids[index] = 1;
//                generate(s, i + word_length, words, used_ids, word_length, res, count + 1);
//            }
//        }
//    }
    void print_map(map<string, int > words){
        map<string, int>::iterator iterator1 = words.begin();
        while(iterator1 != words.end()){
            cout<<iterator1->first<<":"<<iterator1->second<<endl;
            iterator1 ++;
        }
    }
    vector<int> findSubstring_v2(string s, vector<string>& words) {
        vector<int> res = {};
        if(words.empty()) return res;
        int word_length = int(words[0].length());
        int total_length = int(words.size() * word_length);
        if(total_length > s.length()){
            return res;
        }
        map<string, int> word_count_original;
        map<string, int> word_count;
        for(int i=0;i<words.size();i++){
            if(word_count.count(words[i]) == 0){
                word_count[words[i]] = 1    ;
            }else{
                word_count[words[i]] = word_count[words[i]] + 1;
            }

        }
        word_count_original = word_count;
        print_map(word_count_original);
        int start = 0;
        map<string, int > cur_count;
        map<string, int > cur_count_original;
        for(int i=0;i<words.size();i++){
            cur_count[words[i]] = 0;
        }
        cur_count_original = cur_count;
        print_map(cur_count_original);
        for(int i=0;i<s.length();){
            bool not_found_str = false;
            bool insufficient_word = false;
            int pos = i;
            while(true){
                string cur_str = s.substr(pos, word_length);
                if(word_count.count(cur_str) == 0){
                    not_found_str = true;
                    break;
                }else{
                    if(cur_count[cur_str] < word_count[cur_str]){
                        cur_count[cur_str] += 1;
                        pos += word_length;
                        continue;
                    }else{
                        insufficient_word = true;
                        break;
                    }
                }
            }
            cout<<"i="<<i<<", pos="<<pos<<endl;
            if((pos - i) == total_length){
                res.push_back(i);
                i += 1;
            }else{
                if(not_found_str){
                    i += 1;
                }else{
                    i += 1;
                }
            }
            word_count = word_count_original;
            cur_count = cur_count_original;
        }
        return res;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res = {};
        if(words.empty()) return res;
        int word_length = int(words[0].length());
        int total_length = int(words.size() * word_length);
        if(total_length > s.length()){
            return res;
        }
        map<string, int> word_count;
        for(int i=0;i<words.size();i++){
            if(word_count.count(words[i]) == 0){
                word_count[words[i]] = 1;
            }else{
                word_count[words[i]] = word_count[words[i]] + 1;
            }

        }
        for(int i=0;i<word_length;i++){
            map<string, int > seen;
            int l = i;
            int cur = l;
            int count = 0;
            while(cur <= (s.length() - (words.size()-count) * word_length)){
                string cur_str = s.substr(cur, word_length);
                if(word_count.count(cur_str) == 0){
                    cur += word_length;
                    count = 0;
                    // cout<<word_count.count(cur_str)<<endl;
                    l = cur;
                    seen = map<string, int>();
                    continue;
                }
                seen[cur_str] += 1;
                cur += word_length;
                count += 1;
                while(seen[cur_str] > word_count[cur_str]){
                    string tmp = s.substr(l, word_length);
                    seen[tmp] -= 1;
                    l += word_length;
                    count -= 1;
                }
                if(count == words.size()){
                    res.push_back(l);
                }
            }
        }
        return res;
    }
};
class SubstringwithConcatenationofAllWords{
public:
    static void print_vector(vector<int> xs){
        for(int i=0;i<xs.size();i++){
            cout<<xs[i]<<",";
        }
        cout<<endl;
    }
    static void test(){
        vector<string> words = {"foo","bar"};
        string s = "barfoothefoobarman";
        Solution solution = Solution();
        print_vector(solution.findSubstring(s, words));
    }
};