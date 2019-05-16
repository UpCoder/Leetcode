//
// Created by 梁栋 on 2019-05-16.
//
#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void invertTreeBase(TreeNode* root){
        if(root == NULL)
            return;
        invertTreeBase(root->left);
        invertTreeBase(root->right);
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
    TreeNode* invertTree(TreeNode* root) {
        invertTreeBase(root);
        return root;
    }
    TreeNode* invertTreeV2(TreeNode* root){
        stack<TreeNode*> stack1;
        stack1.push(root);
        while(!stack1.empty()){
            TreeNode* cur = stack1.top();
            stack1.pop();
            if(cur != NULL){
                stack1.push(cur->left);
                stack1.push(cur->right);
                swap(cur->left, cur->right);
            }
        }
        return root;
    }
};