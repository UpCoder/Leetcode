//
// Created by 梁栋 on 2019-04-30.
//
#include <vector>
#include <iostream>
using namespace std;
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
class Solution {
public:
    int largestRectangleAreaBase(const vector<int >& heights, int l, int r){
        if(l > r)
            return 0;
        int min_height = -1;
        int min_height_index = l;
        bool increase_sorted = true;
        bool decrease_sorted = true;
        for(int i=l;i<=r;i++){
            if(min_height == -1 || min_height > heights[i]){
                min_height = heights[i];
                min_height_index = i;
            }
            if(i != r && heights[i] > heights[i + 1]){
                increase_sorted = false;
            }
            if(i != r && heights[i] < heights[i + 1]){
                decrease_sorted = false;
            }
        }
        if(increase_sorted){
            int res = 0;
            for(int i=r;i>=l;i--){
                res = max(res, heights[i] * (r-i+1));
            }
            return res;
        }
        if(decrease_sorted){
            int res = 0;
            for(int i=l;i<=r;i++){
                res = max(res, heights[i] * (i-l+1));
            }
            return res;
        }
        int res = min_height * (r - l + 1);
        res = max(res, max(
                largestRectangleAreaBase(heights, l, min_height_index-1),
                largestRectangleAreaBase(heights, min_height_index + 1, r)));
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int l = 0;
        int r = (int) heights.size()-1;
        res = largestRectangleAreaBase(heights, l, r);
        return res;
    }
    static void solution(){
        vector<int> heights = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        Solution solution1;
        cout<<solution1.largestRectangleArea(heights)<<endl;
    }
};