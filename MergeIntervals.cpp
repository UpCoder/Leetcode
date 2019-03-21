//
// Created by 梁栋 on 2019-03-21.
//
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}

};
bool compare(Interval a, Interval b){
    return a.start < b.start;
}
class Solution {
public:

    bool is_interval(Interval self, Interval x){
        int max_start = max(self.start, x.start);
        int min_end = min(self.end, x.end);
        if(max_start > min_end)
            return false;
        return true;
    }
    Interval do_interval(Interval self, Interval x){
        int min_start = min(self.start, x.start);
        int max_end = max(self.end, x.end);
        return Interval(min_start, max_end);
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            Interval cur = res.back();
            if(is_interval(cur, intervals[i])){
                res.pop_back();
                res.push_back(do_interval(cur, intervals[i]));
            }else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
class MergeIntervals{
public:
    static void test(){
        vector<Interval> intervals = {
                Interval(1, 3),
                Interval(2, 6),
                Interval(8, 10),
                Interval(15, 18)
        };
        Solution solution;
        vector<Interval> res = solution.merge(intervals);
        for(int i=0;i<res.size();i++){
            cout<<res[i].start<<", "<<res[i].end<<endl;
        }
    }
};
