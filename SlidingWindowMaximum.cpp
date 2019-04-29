//
// Created by 梁栋 on 2019-04-27.
//
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
struct Node{
    int v;
    int pos;
    Node(int pos, int v){
        this->pos = pos;
        this->v = v;
    }
    bool operator < (Node a) const  {  return v < a.v; }
    bool operator > (Node a) const  {  return v > a.v; }
};
class Solution {
public:
    vector<int> maxSlidingWindowV2(vector<int>& nums, int k){
        vector<int> res;
        deque<int> deque1; // 用来存储num的坐标
        for(int i=0;i<nums.size();i++){
            if(!deque1.empty() && deque1.front() <= (i-k))
                deque1.pop_front();
            while(!deque1.empty() && nums[deque1.back()] < nums[i])
                deque1.pop_back();
            deque1.push_back(i);
            if(i >= (k-1)){
                res.push_back(nums[deque1.front()]);
            }
        }
        return res;

    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<Node, vector<Node>> queue1;
        for(int i=0;i<nums.size();i++){
            queue1.push(Node(i, nums[i]));
            if(i >= (k-1)){
                while(true){
                    Node node = queue1.top();
                    if(abs(i-node.pos) >= k){
                        queue1.pop();
                        continue;
                    }else{
                        res.push_back(node.v);
                        break;
                    }
                }
            }
        }
        return res;
    }
    static void solution(){
        vector<int> nums = {1, 3, 1, 2, 0, 5};
        int k = 3;
        Solution solution1;
        vector<int> res = solution1.maxSlidingWindowV2(nums, k);
        for(auto i: res) cout<<i<<", ";
        cout<<endl;
    }
};