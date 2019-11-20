//
// Created by Liang on 2019-09-02.
//
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:
    void sum2Solution(vector<int>& C, vector<int>& D, unordered_map<int, int>& record){
        for(auto c: C){
            for(auto d: D){
                record[c + d] = record[c + d] + 1;
            }
        }
    }
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());
        int res = 0;
        unordered_map<int, int> record;
        sum2Solution(C, D, record);
        for(auto num1: A){
            for(auto num2: B){
                res += record[-(num1 + num2)];
            }
        }
        return res;
    }
    static void solution(){
        vector<int> A = {1, 2};
        vector<int> B = {-2,-1};
        vector<int> C = {-1, 2};
        vector<int> D = {0, 2};
        Solution solution1;
        cout<<solution1.fourSumCount(A, B, C, D)<<endl;
    }
};