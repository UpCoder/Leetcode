//
// Created by 梁栋 on 2019-05-01.
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
    bool isSymmetricBase(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL)
            return true;
        if(root1 == NULL || root2 == NULL)
            return false;
        return (root1->val == root2->val)
        && isSymmetricBase(root1->left, root2->right)
        && isSymmetricBase(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetricBase(root, root);
    }
};
