//
// Created by Liang on 2019-07-06.
//
#include <vector>
#include <iostream>
#include <deque>
#include <list>
using namespace std;
bool compare_QRH(vector<int> a, vector<int> b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    return a[0] > b[0];
}
class Solution {
public:
    bool check(vector<int> query, const vector<vector<int>>& sorted){
        int count = 0;
        for(auto ele: sorted){
            if(ele[0] >= query[0]){
                count += 1;
            }
        }
        if(count != query[1])
            return false;
        return true;
    }

    void reconstructQueueCore(const vector<vector<int>>& people, vector<vector<int>>& sorted, bool* used, int size){
        if(sorted.size() == people.size()){
            return;
        }
        for(int i=0;i<size;i++){
            if(used[i]){
                bool add_flag = check(people[i], sorted);
                if(add_flag){
                    used[i] = false;
                    sorted.push_back(people[i]);
                    reconstructQueueCore(people, sorted, used, size);
                    if(sorted.size() == people.size())
                        return;
                    used[i] = true;
                    sorted.pop_back();
                }
            }
        }
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//        vector<vector<int> > sorted;
//        int size = people.size();
//        if(size == 0)
//            return sorted;
//        bool used[size];
//        memset(used, true, sizeof(used));
//        reconstructQueueCore(people, sorted, used, size);
//        return sorted;
        return reconstructQueueN2(people);
    }
    vector<vector<int> > reconstructQueueN2(vector<vector<int>>& people){
        vector<vector<int> > sorted;
        int size = people.size();
        if(size == 0)
            return sorted;
        sort(people.begin(), people.end(), compare_QRH);
        list<vector<int>> list1;
        for(auto ele: people){
            auto it = list1.begin();
            for(int i=0;i<ele[1];i++)
                it++;
            list1.insert(it, ele);
        }
        while(!list1.empty()){
            sorted.push_back(list1.front());
            list1.pop_front();
        }
        return sorted;
    }
    static void solution(){
        Solution solution1;
        vector<vector<int>> input = {
                {40,11},{81,12},{32,60},{36,39},{76,19},{11,37},{67,13},{45,39},{99,0},{35,20},{15,3},{62,13},{90,2},
                {86,0},{26,13},{68,32},{91,4},{23,24},{73,14},{86,13},{62,6},{36,13},{67,9},{39,57},{15,45},{37,26},{12,88},
                {30,18},{39,60},{77,2},{24,38},{72,7},{96,1},{29,47},{92,1},{67,28},{54,44},{46,35},{3,85},{27,9},{82,14},
                {29,17},{80,11},{84,10},{5,59},{82,6},{62,25},{64,29},{88,8},{11,20},{83,0},{94,4},{43,42},{73,9},{57,32},
                {76,24},{14,67},{86,2},{13,47},{93,1},{95,2},{87,8},{8,78},{58,16},{26,75},{26,15},{24,56},{69,9},{42,22},
                {70,17},{34,48},{26,39},{22,28},{21,8},{51,44},{35,4},{25,48},{78,18},{29,30},{13,63},{68,8},{21,38},
                {56,20},{84,14},{56,27},{60,40},{98,0},{63,7},{27,46},{70,13},{29,23},{49,6},{5,64},{67,11},{2,31},
                {59,8},{93,0},{50,39},{84,6},{19,39}
        };
        vector<vector<int>> res = solution1.reconstructQueue(input);
        for(auto ele: res){
            cout<<ele[0]<<", "<<ele[1]<<endl;
        }
    }
};