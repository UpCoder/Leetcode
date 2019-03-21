//
// Created by 梁栋 on 2019-03-20.
//
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        map<string, int> string2index;
        int count = 1;
        for (int i = 0; i < strs.size(); ++i) {
            string cur_str = strs[i];
            string sorted_str = cur_str;
            sort(sorted_str.begin(), sorted_str.end());
            //cout<<"sorted_str is "<<sorted_str<<endl;
            if(string2index[sorted_str] == 0){
                string2index[sorted_str] = count;
                res.push_back({cur_str});
                count += 1;
            }else{
                res[string2index[sorted_str]-1].push_back(cur_str);
            }
        }
        return res;
    }
};
class GroupAnagrams{
public:
    static void test(){
        Solution solution;
        vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
        vector<vector<string> > res = solution.groupAnagrams(strs);
        for(int i=0;i<res.size();i++){
            for(int j=0;j<res[i].size();j++){
                cout<<res[i][j]<<", ";
            }
            cout<<endl;
        }
    }
};