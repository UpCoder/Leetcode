//
// Created by Liang on 2019-08-16.
//
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <queue>
using namespace std;
class Solution {
public:
    bool is_huiwen(string x){
        int e = x.length()-1;
        int s = 0;
        while(s<=e){
            if(x[s] == x[e]){
                s += 1;
                e -= 1;
                continue;
            }
            return false;
        }
        return true;
    }
    vector<vector<string>> partitionCore(vector<string> base, int s, int e){
        vector<vector<string>> res;
        vector<string> new_base;
        for(int i=s;i<e;i++){
            new_base.push_back(base[i]);
        }
        res.push_back(new_base);
        for(int i=2;i<=(e-s);i++){
            string new_str = "";
            for(int j=0;j<i;j++){
                new_str += base[s+j];
            }
            if(is_huiwen(new_str)){
                vector<vector<string>> tmp_res = partitionCore(base, s+i, e);
                for(auto vec: tmp_res){
                    vec.insert(vec.begin(), new_str);
                    res.push_back(vec);
                }
            }else{
                continue;
            }
        }
        return res;

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> base;
        for(auto c: s){
            base.push_back(string(1, c));
        }
        res = partitionCore(base, 0, base.size());
        return res;
    }
    vector<vector<string>> partitionV2(string s) {
        vector<vector<string>> res;
        int len = s.length();
        vector<string> base;
        for(auto c: s){
            base.push_back(string(1, c));
        }
        res.push_back(base);
        long long max_x = pow(2., len - 1) - 1;
        for(long long i=1;i<=max_x;i++){

            vector<int> is_merged(len-1, 0);
            int idx = 0;
            int bin_i = i;
            while(bin_i >0){
                is_merged[idx] = bin_i & 1;
                bin_i = bin_i >> 1;
                idx += 1;
            }
            vector<string> tmp;
            string cur_string = base[0];
            idx = 1;
            bool is_added2res = true;
            for(auto flag: is_merged){
                if(flag == 1){
                    cur_string += base[idx];
                    idx += 1;
                }
                else{
                    if(is_huiwen(cur_string)){
                        tmp.push_back(cur_string);
                        cur_string = base[idx];
                        idx += 1;
                    }else{
                        is_added2res = false;
                        break;
                    }
                }
            }

            if(is_added2res){
                if(is_huiwen(cur_string)){
                    tmp.push_back(cur_string);
                    res.push_back(tmp);
                    continue;
                }else{
                    continue;
                }
            }
        }

        return res;
    }


    static void solution(){
        string input = "seeslaveidemonstrateyetartsnomedievalsees";
        Solution solution1;
        vector<vector<string>> res = solution1.partitionV2(input);
        for(auto vec: res){
            for(auto str: vec){
                cout<<str<<",";
            }
            cout<<endl;
        }
    }
};