//
// Created by Liang on 2019-07-07.
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
    void midlevel(TreeNode* root, vector<int>& nums){
        if(root == NULL){
            return;
        }
        if(root->left){
            midlevel(root->left, nums);
        }
        nums.push_back(root->val);
        if(root->right){
            midlevel(root->right, nums);
        }
    }
    vector<int> cal_sum(vector<int> nums){
        int sum=0;
        vector<int> res;
        for(auto i: nums){
            sum += i;
        }
        for(auto i:nums){
            res.push_back(sum - i);
            sum -= i;
        }
        return res;
    }
    TreeNode* cloneBST(TreeNode* root, const vector<int>& greater_sum, int& loc){
        if(root == NULL)
            return NULL;
        TreeNode* new_root = new TreeNode(0);
        if(root->left){
            new_root->left = cloneBST(root->left, greater_sum, loc);
        }
        new_root->val = root->val + greater_sum[loc];
        loc += 1;
        if(root->right){
            new_root->right = cloneBST(root->right, greater_sum, loc);
        }
        return new_root;
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL)
            return NULL;
        vector<int> nums;
        midlevel(root, nums);
        vector<int> greater_sum = cal_sum(nums);
        int s = 0;
        return cloneBST(root, greater_sum, s);
    }
    static void solution(){
        TreeNode* root = TreeNode::buildByLevel({5, 2, 13});
        TreeNode::levelOrder(root);
        Solution solution1;
        TreeNode* res = solution1.convertBST(root);
        TreeNode::levelOrder(res);
    }
};