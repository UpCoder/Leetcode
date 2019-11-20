//
// Created by Liang on 2019-09-05.
//
#include <vector>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};
class NestedIterator {
public:
    vector<int> all_nums;
    int cur_index;
    NestedIterator(vector<NestedInteger> &nestedList) {
        all_nums = vector<int>();
        for(int i=0;i<nestedList.size();i++){
            iter(nestedList[i]);
        }
        cur_index = 0;
    }
    void iter(NestedInteger nestedList){
        if(nestedList.isInteger()){
            all_nums.push_back(nestedList.getInteger());
            return;
        }
        for(int i=0;i<nestedList.getList().size();i++){
            iter(nestedList.getList()[i]);
        }
    }
    int next() {
        int res = all_nums[cur_index];
        cur_index += 1;
        return res;
    }

    bool hasNext() {
        return cur_index < all_nums.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */