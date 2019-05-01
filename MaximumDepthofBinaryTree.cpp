//
// Created by 梁栋 on 2019-05-01.
//

#include <vector>
#include <queue>
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
    int maxDepthBase(TreeNode* root, int height){
        if(root == NULL){
            return height;
        }
        return max(maxDepthBase(root->left, height + 1), maxDepthBase(root->right, height + 1));
    }
    int maxDepth(TreeNode* root) {
        return maxDepthBase(root, 0);
    }
    static void solution(){
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);
        root->right->right->right = new TreeNode(7);
        root->right->right->right->left = new TreeNode(7);
        Solution solution1;
        cout<<solution1.maxDepth(root)<<endl;
    }
};