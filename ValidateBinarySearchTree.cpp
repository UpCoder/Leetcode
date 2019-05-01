//
// Created by 梁栋 on 2019-04-30.
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
    bool isValidBSTBase(TreeNode* root, int* min_val, int* max_val){
        if(root == NULL)
            return true;
        if(min_val != NULL && (*min_val) >= root->val)
            return false;
        if(max_val != NULL && (*max_val) <= root->val)
            return false;
        return isValidBSTBase(root->left, min_val, &root->val)
        && isValidBSTBase(root->right, &root->val, max_val);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBSTBase(root, NULL, NULL);
    }
    bool isValidBSTIterating(TreeNode* root){
        stack<TreeNode*> stack1;
        int* last_value = NULL;
        while(root != NULL || !stack1.empty()){
            while(root != NULL){
                stack1.push(root);
                root = root->left;
            }
            root = stack1.top();
            stack1.pop();
            if(last_value == NULL){
                last_value = &(root->val);
            }else{
                if((*last_value) >= root->val){
                    return false;
                }
                last_value = &(root->val);
            }
            root = root->right;
        }
        return true;
    }
    static void solution(){
        TreeNode* root = new TreeNode(5);
        root->left = new TreeNode(1);
        root->right = new TreeNode(4);
        root->right->left = new TreeNode(3);
        root->right->right = new TreeNode(6);
        Solution solution1;
        cout<<solution1.isValidBSTIterating(root)<<endl;
    }
};