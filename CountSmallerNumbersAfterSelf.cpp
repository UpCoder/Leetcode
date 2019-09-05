//
// Created by Liang on 2019-08-28.
//
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
class BSTNode{
public:
    int val;
    int left;
    int right;
    BSTNode* lChild;
    BSTNode* rChild;
    int count;
    BSTNode(int v){
        this->val = v;
        this->count = 1;
        this->left = 0;
        this->right = 0;
        this->lChild = NULL;
        this->rChild = NULL;
    }
};
class BST{
public:
    BSTNode* root;
    BST(){
        root = NULL;
    }
    void insert(int v){
        if(root == NULL){
            root = new BSTNode(v);
            return;
        }
        insert(this->root, v);
    }
    void insert(BSTNode* root, int v){
        if(root->val == v){
            root->count += 1;
            return;
        }
        if(root->val < v){
            root->right += 1;
            if(root->rChild){
                insert(root->rChild, v);
            }else{
                root->rChild = new BSTNode(v);
            }
        }else{
            root->left += 1;
            if(root->lChild){
                insert(root->lChild, v);
            }else{
                root->lChild = new BSTNode(v);
            }
        }
    }
    int search(BSTNode* root, int target){
        if(root->val == target){
            return root->left;
        }
        if(root->val < target){
            return root->left + root->count + search(root->rChild, target);
        }
        if(root->val > target){
            return search(root->lChild, target);
        }
        return 0;
    }
};
class MergeSort{
public:
    vector<int> mergeSort(vector<int>& nums){
        vector<int> res = {};
        int size = nums.size();
        if(size == 0)
            return res;
        vector<int> indexs(size, 0);
        iota(indexs.begin(), indexs.end(), 0);
        vector<int> results(size, 0);
        mergeSortCore(nums, 0, size-1, indexs, results);
        return results;
    }
    void mergeSortCore(const vector<int>& nums, int s, int e, vector<int>& indexs, vector<int>& results){
        if(e > s){
            int mid = (s + e) >> 1;
            mergeSortCore(nums, s ,mid, indexs, results);
            mergeSortCore(nums, mid + 1, e, indexs, results);
            vector<int> tmp;
            int start = s;
            int l = s;
            int r = mid + 1;
            int cnt = 0;
            while(l <= mid && r <= e){
                // 注意，前后两个子序列都是从小到达排序的
                if(nums[indexs[l]]>nums[indexs[r]]){
                    // 后面小于前面
                    cnt += 1;
                    tmp.push_back(indexs[r]);
                    r += 1;
                }else{
                    // 前面小于后面了
                    results[indexs[l]] += cnt;
                    tmp.push_back(indexs[l]);
                    l += 1;
                }
            }
            while(l <= mid){
                tmp.push_back(indexs[l]);
                results[indexs[l]] += cnt;
                l += 1;
            }
            while(r <= e){
                tmp.push_back(indexs[r]);
                r += 1;
            }
            for(int i=s;i<=e;i++){
                indexs[i] = tmp[i-s];
            }
        }
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size() == 0)
            return {};
        MergeSort ms;
        return ms.mergeSort(nums);
//        BST bst;
//        vector<int> result = {0};
//        bst.insert(nums[nums.size()-1]);
//        for(int i=nums.size()-2;i>=0;i--){
//
//            bst.insert(nums[i]);
//            result.push_back(bst.search(bst.root, nums[i]));
//
//        }
//        reverse(result.begin(), result.end());
//        return result;

//        multiset<int, less<int >> queue;
//        vector<int> result = {0};
//        for(int i=nums.size()-1;i>=0;i--){
//            if(queue.empty()){
//                queue.insert(nums[i]);
//                continue;
//            }else{
//                int count = distance(queue.begin(), queue.lower_bound(nums[i]));
//                result.push_back(count);
//                queue.insert(nums[i]);
//
//            }
//        }
//        reverse(result.begin(), result.end());
//        return result;
    }
    static void solution(){
        vector<int> nums = {5,2,6,1};
        Solution solution1;
        vector<int> result = solution1.countSmaller(nums);
        for(auto ele: result){
            cout<<ele<<endl;
        }
    }
};