//
// Created by Liang on 2019-08-25.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
class Building{
public:
    int x;
    int height;
    int type;
    Building(){

    }
    Building(int loc, int height, int type){
        this->x = loc;
        this->height = height;
        this->type = type;
    }
};
struct cmp{
    bool operator ()(Building a, Building b){
        if(a.x > b.x)
            return true;
        if(a.x < b.x)
            return false;
        if(a.type > b.type)
            return true;
        return false;
    }
};
struct cmp_greater_int{
    inline bool operator ()(const int& a, const int& b) const {
        if(a > b){
            return true;
        }
        return false;
    }
};
class Solution {
public:
    vector<vector<int>> getSkylineV2(vector<vector<int>>& buildings) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater_equal<pair<int, int >>> pq;
        for(auto ele: buildings){
            pq.push(pair<int, int>(ele[0], -ele[2]));
            pq.push(pair<int, int>(ele[1], ele[2]));
        }
        multiset<int> heights = {0};
        vector<vector<int>> result;
        int max = 0;
        while(!pq.empty()){
            pair<int, int> cur = pq.top();
            pq.pop();
            if(cur.second < 0){
                heights.insert(-cur.second);
            }else{
                heights.erase(heights.find(cur.second)); // 删除元素
            }
            if(max != (*heights.rbegin())){
                max = *heights.rbegin();
                result.push_back({cur.first, *heights.rbegin()});
            }
        }
        return result;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<Building, vector<Building>, cmp> pq;
        int max_x = -1;
        for(auto ele: buildings){
            pq.push(Building(ele[0], ele[2], 0));
            pq.push(Building(ele[1], ele[2], 1)); // 加入尾端类型的节点
            max_x = max(max_x, ele[1]);
        }
        multiset<int, cmp_greater_int> maintain_heights; // 维护当前的高度, 最大队列
        int max = 0;
        vector<vector<int>> result;
        maintain_heights.insert(0);
        while(!pq.empty()){
            Building cur = pq.top();
            pq.pop();
            if(cur.type == 0){
                maintain_heights.insert(cur.height);    // 如果是起点，加入
            }else{
                maintain_heights.erase(maintain_heights.lower_bound(cur.height)); // 如果是终点，直接删除
            }
            while(!pq.empty() && (pq.top().x == cur.x)){
                cur = pq.top();
                pq.pop();
                if(cur.type == 0){
                    maintain_heights.insert(cur.height);    // 如果是起点，加入
                }else{
                    maintain_heights.erase(maintain_heights.lower_bound(cur.height)); // 如果是队尾元素的话，直接删除
                }
            }
            if(!maintain_heights.empty() && (*maintain_heights.begin() != max)){
                max = (*maintain_heights.begin());
                vector<int> tmp;
                tmp.push_back(cur.x);
                tmp.push_back(max);
                result.push_back(tmp);
            }
        }
        //result.push_back({max_x, 0});
        return result;
    }
    static void solution(){
        set<int, cmp_greater_int> tmp;
        tmp.insert(3);
        tmp.insert(10);
        tmp.insert(0);
        cout<<*tmp.begin()<<endl;
        Solution solution1;
        vector<vector<int>> buildings = {
//                {2, 9, 10},
//                {3, 7, 15},
//                {5, 12, 12},
//                {15, 20, 10},
//                {19, 24, 8}
                {0, 2, 3},
                {2, 5, 3}
        };
        vector<vector<int>> result = solution1.getSkylineV2(buildings);
        for(auto ele: result){
            cout<<ele[0]<<","<<ele[1]<<endl;
        }
    }
};