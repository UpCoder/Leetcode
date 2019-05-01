//
// Created by 梁栋 on 2019-04-30.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    void inorderTraversalBase(TreeNode* root, vector<int>& res){
        if(root == NULL)
            return;
        inorderTraversalBase(root->left, res);
        res.push_back(root->val);
        inorderTraversalBase(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderTraversalBase(root, res);
        return res;
    }
    vector<int> inorderTraversalIterating(TreeNode* root){
        stack<TreeNode* > stack1;
        vector<int> res;
        while(root != NULL || !stack1.empty()){
            while(root){
                stack1.push(root);
                root = root->left;
            }
            // 没有左孩子，则当前节点就应该加入队列中。
            root = stack1.top();
            res.push_back(root->val);
            stack1.pop();
            root = root->right;
        }
        return res;
    }
};