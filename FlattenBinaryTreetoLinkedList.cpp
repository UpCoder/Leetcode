//
// Created by 梁栋 on 2019-05-01.
//
#include <vector>
#include <stack>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> nodes;
        stack<TreeNode*> stack1;
        TreeNode* cur = root;
        while(cur != NULL || !stack1.empty()){
            while (cur){
                stack1.push(cur);
                nodes.push_back(cur);
                cur = cur->left;

            }
            cur = stack1.top();
            stack1.pop();
            cur = cur->right;
        }
        cur = root;
        for(int i=1;i<nodes.size();i++){
            cur->right = nodes[i];
            cur->left = NULL;
            cur = cur->right;
        }
        cur->right = NULL;
    }
    TreeNode* prev = NULL;
    void flattenV2(TreeNode* root){
        if(root == NULL)
            return;
        flattenV2(root->right);
        flattenV2(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
    static void solution(){
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(4);
        root->right = new TreeNode(5);
        root->right->right = new TreeNode(6);
        Solution solution1;
        solution1.flatten(root);
        while(root){
            cout<<root->val<<"->";
            root = root->right;
        }
        cout<<endl;

    }
};