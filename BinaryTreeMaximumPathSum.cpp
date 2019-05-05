//
// Created by 梁栋 on 2019-05-02.
//

#include <vector>
#include <iostream>
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
    int maxPathSumBase(TreeNode* root, int& res){
        if(root == NULL)
            return 0;
        int leftSum = max(0, maxPathSumBase(root->left, res)); // 如果左子树的和小于0， 则忽略不计
        int rightSum = max(0, maxPathSumBase(root->right, res)); // 如果右子树的和小于0， 则忽略不计
        res = max(res, leftSum + rightSum + root->val); // 结果左子树+右子树+root 因为左子树和右子树>=0;
        return max(leftSum, rightSum) + root->val;  // 如果结果在上面，则肯定需要加入root节点的value。

    }
    int maxPathSum(TreeNode* root) {
        int res = 0x7FFFFFF;
        res = -res - 1;
        cout<<res<<endl;
        maxPathSumBase(root, res);
        return res;
    }
    static void solution(){
//        vector<int> nums = {5, 4, 8, 11, 0, 13, 4, 7, 2, 0, 0, 0, 1}; // 48
//        vector<int> nums = {1, 2, 3}; // 6
//        vector<int> nums = {-10,9,20,0,0,15,7}; // 42
        vector<int> nums = {-3}; // -3
//        vector<int> nums = {1, -2, -3, 1, 3, -2, 0, -1, 0}; // 3
//        vector<int> nums = {1,0,1,1,2,0,-1,0,1,-1,0,-1,0,1,0}; // 4
        TreeNode* root = TreeNode::buildByLevel(nums);
        TreeNode::levelOrder(root);
//        root->right = new TreeNode(-3);
//        root->left->left = new TreeNode(1);
//        root->left->right = new TreeNode(3);
//        root->left->left->left = new TreeNode(-1);
//        root->right->left = new TreeNode(-2);
//        root->left = new TreeNode(9);
//        root->right = new TreeNode(20);
//        root->right->left = new TreeNode(15);
//        root->right->right = new TreeNode(7);
        Solution solution1;
        cout<<solution1.maxPathSum(root)<<endl;
    }
};