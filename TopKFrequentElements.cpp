//
// Created by Liang on 2019-06-28.
//
#include <vector>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
struct cmp
{
    bool operator()(map<int, int>::iterator it1, map<int, int>::iterator it2)
    {

        if(it1->second > it2->second){
            return true;
        }
        return false;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> count_map;    // 计算每个数字出现的次数
        vector<int> res;
        if(k==0)
            return res;
        priority_queue<map<int, int>::iterator, vector<map<int, int>::iterator>, cmp> q;
        for(int i=0;i<nums.size();i++){
            count_map[nums[i]] += 1;
        }
        map<int, int>::iterator it = count_map.begin();
        while(it != count_map.end()){
            if(q.size() < k){
                q.push(it);

            }else{
                q.push(it);
                q.pop();
            }
            it ++;
        }
        while(!q.empty()){
            res.push_back(q.top()->first);
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    static void solution(){
        Solution solution1;
        vector<int> nums = {1, 2, 2, 2, 3, 3, 3, 3};
        vector<int> res = solution1.topKFrequent(nums, 2);
        for(auto i: res){
            cout<<i<<",";
        }
        cout<<endl;
    }
};