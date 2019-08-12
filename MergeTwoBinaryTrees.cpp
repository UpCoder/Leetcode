//
// Created by Liang on 2019-07-10.
//
#include <vector>
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mergeTreesCore(TreeNode* t1, TreeNode* t2){
        if(t1 == NULL && t2 == NULL)
            return NULL;
        int cur = 0;
        if(t1 != NULL)
            cur += t1->val;
        if(t2 != NULL)
            cur += t2->val;
        TreeNode* root = new TreeNode(cur);
        if(t1 == NULL){
            root->left = mergeTreesCore(NULL, t2->left);
            root->right = mergeTreesCore(NULL, t2->right);
        }else{
            if(t2 == NULL){
                root->left = mergeTreesCore(t1->left, NULL);
                root->right = mergeTreesCore(t1->right, NULL);
            }else{
                root->left = mergeTreesCore(t1->left, t2->left);
                root->right = mergeTreesCore(t1->right, t2->right);
            }
        }
        return root;

    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return mergeTreesCore(t1, t2);
    }
};