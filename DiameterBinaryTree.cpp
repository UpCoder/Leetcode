//
// Created by Liang on 2019-07-09.
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
    static TreeNode* buildByLevel(vector<int> nums, int null_target=0){
        TreeNode* root = new TreeNode(nums[0]);

        queue<TreeNode* > queue1;
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
    static void levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> cur_level;
        int nums = 1;
        int count = 0;
        queue<TreeNode*> nodes;
        nodes.push(root);
        int next_levels_num = 0;

        while(!nodes.empty()){
            TreeNode* cur_node = nodes.front();
            nodes.pop();
            if(cur_node != NULL){
                nodes.push(cur_node->left);
                nodes.push(cur_node->right);
                cur_level.push_back(cur_node->val);
                next_levels_num += 2;
            }
            count += 1;
            if(count == nums){
                nums = next_levels_num;
                next_levels_num = 0;
                count = 0;
                res.push_back(cur_level);
                cur_level = {};
            }
        }
        for(auto v: res){
            for(auto e: v){
                cout<<e<<", ";
            }
            cout<<endl;
        }
    }
};
class Solution {
public:
    int diameterOfBinaryTreeCore(TreeNode*& root, int& res){
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            res = max(res, 1);
            return 1;
        }
        int left_len_path = diameterOfBinaryTreeCore(root->left, res);
        int right_len_path = diameterOfBinaryTreeCore(root->right, res);
        res = max(res, left_len_path + right_len_path + 1);
        return max(left_len_path, right_len_path) + 1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        diameterOfBinaryTreeCore(root, res);
        res -= 1;
        res = max(res, 0);
        return res;
    }
    static void solution(){
        TreeNode* treeNode = TreeNode::buildByLevel({1, 2, 3, 4, 5, -1, -1}, -1);
        Solution solution1;
        cout<<solution1.diameterOfBinaryTree(treeNode)<<endl;
    }
};