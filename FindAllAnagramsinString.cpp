//
// Created by Liang on 2019-07-07.
//
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool meet_cond(const string& string1, int s, unordered_map<char, int> p_dict, const int& p_len, int& next_local){
        unordered_map<char, int> tmp;
        unordered_map<char, int > location;
        for(int i=0;i<p_len;i++){
            char cur = string1[s + i];
            tmp[cur] += 1;
            if(tmp[cur] > p_dict[cur]){
                if(p_dict[cur] == 0){
                    next_local = s + i + 1;
                }else{
                    // 该元素多了，所以需要减少一个，找到第一个出现该元素的位置
                    next_local = location[cur];
                }
                return false;
            }
            if(location[cur] == 0){
                // 保留第一次出现的位置
                location[cur] = s + i + 1;
            }

        }
        return true;
    }
    vector<int> findAnagramsCore(string s, string p){
        vector<int> res;
        if(s.length() == 0)
            return res;
        int idx = 0;
        unordered_map<char, int> p_dict;
        for(auto c: p){
            p_dict[c] = p_dict[c] + 1;
        }
        int s_len = s.length();
        int p_len = p.length();
        int idx_s = 0;
        int idx_e = 0;
        int ele_sum = 0;
        unordered_map<char, int> show_dict;
        while(idx_e < s_len){
            char added_char = s[idx_e];
            if(p_dict[added_char] == 0){
                // 没有出现
                idx_s = idx_e + 1;
                idx_e = idx_e + 1;
                show_dict = unordered_map<char, int>();
                ele_sum = 0;
            }else{
                // 出现过
                if(show_dict[added_char] < p_dict[added_char]){
                    // 还不够
                    show_dict[added_char] += 1;
                    ele_sum += 1;
                    if(ele_sum == p_len){
                        res.push_back(idx_s);
                    }
                    idx_e += 1;
                }else{
                    // 超了，需要跳跃
                    while(s[idx_s] != added_char){
                        show_dict[s[idx_s]] -= 1;
                        idx_s += 1;
                        ele_sum -= 1;

                    }
                    idx_s += 1;
                    if(ele_sum == p_len){
                        res.push_back(idx_s);
                    }
                    idx_e += 1;
                }
            }
        }
        return res;
    }
    vector<int> findAnagrams(string s, string p) {
        return findAnagramsCore(s, p);
//        vector<int> res;
//        if(s.length() == 0)
//            return res;
//        int idx = 0;
//        unordered_map<char, int> p_dict;
//        for(auto c: p){
//            p_dict[c] = p_dict[c] + 1;
//        }
//        int s_len = s.length();
//        int p_len = p.length();
//        int i=0;
//        while(i<=(s_len - p_len)){
//            int next_local = i + 1;
//            bool meet_flag = meet_cond(s, i, p_dict, p_len, next_local);
//            if(meet_flag){
//                res.push_back(i);
//                while(i<(s_len - p_len) && s[i] == s[i + p_len]){
//                    i += 1;
//                    res.push_back(i);
//                }
//                if(i > (s_len - p_len))
//                    break;
//                // s[i] != s[i + p+len]
//
//                if(p_dict[s[i + p_len]] == 0){
//                    // s[i + p+len]没有出现在p里面
//                    i = i + p_len + 1;
//                    continue;
//                }else{
//                    // s[i + p+len] 出现在了p里面
//                    char target = s[i + p_len];
//                    for(int j=1;j<p_len;j++){
//                        if(s[i + j] == target){
//                            i = i + j + 1;
//                            break;
//                        }
//                    }
//                }
//            }else{
//                i = next_local;
//            }
//        }
//        return res;
    }
    static void solution(){
        Solution solution1;
        string s = "abacbabc";
        string p = "abc";
        cout<<s<<endl;
        cout<<p<<endl;
        vector<int> res = solution1.findAnagrams(s, p);
        for(auto i: res){
            cout<<i<<",";
        }
        cout<<endl;
    }
};
//"abacbabc"
//"abc"