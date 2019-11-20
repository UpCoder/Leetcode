//
// Created by Liang on 2019-09-03.
//
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;
class RandomizedSet {
private:
    unordered_map<int, int> exisit;
    vector<int> vals;
    int num_vals;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        num_vals = 0;
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(exisit.count(val) != 0){
            return false;
        }else{
            this->vals.push_back(val);
            exisit[val] = this->vals.size();
            return true;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(exisit.count(val) == 0){
            return false;
        }
        auto it = exisit.find(val);
        if(it->second == this->vals.size()){
            // 刚好是最后一个
            this->vals.pop_back();
        }else{
            auto it_2 = exisit.find(vals[vals.size()-1]);
            swap(vals[it->second-1], vals[vals.size()-1]);
            this->vals.pop_back();
            exisit[it_2->first] = it->second;
        }
        exisit.erase(it);
    }

    /** Get a random element from the set. */
    int getRandom() {
        int cur_idx = rand() % this->vals.size();
        return this->vals[cur_idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
 class Solution{
 public:
     static void solution(){

     }
 };