//
// Created by 梁栋 on 2019-05-09.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    static TreeNode* buildByLevel(vector<int> nums){
        TreeNode* root = new TreeNode(nums[0]);

        queue<TreeNode* > queue1;
        int null_target = 0;
        queue1.push(root);
        for(int i=1;i<nums.size();i+=2){
            int lchild = nums[i];
            int rchild = nums[i+1];
            TreeNode* cur = queue1.front();
            queue1.pop();
            if(lchild != null_target){
                cur->left = new TreeNode(lchild);
                queue1.push(cur->left);
            }
            else
                cur->left= NULL;
            if(rchild != null_target){
                cur->right = new TreeNode(rchild);
                queue1.push(cur->right);
            }
            else
                cur->right = NULL;
        }
        return root;
    }
};
class Result{
public:
    int low_level;
    int high_level;
    Result(){
        low_level = 0;
        high_level = 0;
    }
};
class Solution {
public:
    int robBase(TreeNode* root, bool flag){
        if(root == NULL)
            return 0;
        int res;
        if(flag){
            res = max(
                    root->val + robBase(root->left, false) + robBase(root->right, false),
                    robBase(root->left, true) + robBase(root->right, true));
        }else{
            res = robBase(root->left, true) + robBase(root->right, true);
        }
        return res;
    }
    Result robBase(TreeNode* root){
        if(root == NULL)
        {
            return Result();
        }
        Result left = robBase(root->left);
        Result right = robBase(root->right);
        int max_value = max(root->val + left.low_level + right.low_level, left.high_level + right.high_level);
        Result res;
        res.high_level = max_value;
        res.low_level = left.high_level + right.high_level;
        return res;

    }
    int rob(TreeNode* root) {
         // int res = robBase(root, true);
        if(root == NULL)
            return 0;
        Result res = robBase(root);
        return res.high_level;
    }
    static void solution(){
        vector<int> nums = {3, 2, 3, 0, 3, 0, 1};
//        vector<int> nums = {3};
//        vector<int> nums = {4,1,0,2,0,3,0};
//        vector<int> nums = {3, 4, 5, 1, 3, 0, 1};
        TreeNode* root = TreeNode::buildByLevel(nums);
        Solution solution1;
        cout<<solution1.rob(root)<<endl;
    }
};