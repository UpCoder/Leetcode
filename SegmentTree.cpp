//
// Created by 梁栋 on 2019-04-30.
//
#include <vector>
#include <iostream>
using namespace std;
#define MAX_INF 0x7FFFFFFF
class Node{
public:
    int l, r;
    int min_val;
    Node(){
        this->min_val = MAX_INF;
    }
};
class SegmentTree{
public:
    Node* nodes;
    SegmentTree(int n){
        nodes = new Node[4 * n + 1];
    }
    void build(vector<int> nums, int k, int l, int r){
        // 根据数组构建线段树
        // build(nums, 0, 0, nums.size()-1);
        int n = (int) nums.size();
        this->nodes[k].l = l;
        this->nodes[k].r = r;
        if(l == r){
            this->nodes[k].min_val = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(nums, k*2+1, l, mid);
        build(nums, k*2+2, mid+1, r);
        this->nodes[k].min_val = min(this->nodes[2*k+1].min_val, this->nodes[2*k+2].min_val);
    }

    int search(int k, int l, int r){
        if(this->nodes[k].l > r || this->nodes[k].r < l)
            return MAX_INF;
        if(this->nodes[k].l >= l && this->nodes[k].r <= r)
            return this->nodes[k].min_val;
        return min(search(k*2+1, l, r), search(k*2+2, l, r));
    }
};
class Solution{
public:
    static void solution(){
        vector<int> heights = {1, 3, 6, 2, 0, 5};
        SegmentTree lineTree((int)heights.size());
        lineTree.build(heights, 0, 0, heights.size()-1);
        cout<<lineTree.search(0, 1, 4);
    }
};