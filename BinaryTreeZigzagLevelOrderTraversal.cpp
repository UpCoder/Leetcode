//
// Created by Liang on 2019-08-11.
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
        int null_target = -1;
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool first_left = false;
        queue<TreeNode*> nodes;
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }
        nodes.push(root);
        while(!nodes.empty()){
            int num_cur_level = nodes.size();
            vector<int> cur_level;
            for(int i=0;i<num_cur_level;i++){
                TreeNode* cur_node = nodes.front();
                cur_level.push_back(cur_node->val);
                nodes.pop();
                if(cur_node->right){
                    nodes.push(cur_node->right);
                }
                if(cur_node->left){
                    nodes.push(cur_node->left);
                }
            }
            if(first_left){
                first_left = false;
            }else{
                first_left = true;
                // 需要reverse
                reverse(cur_level.begin(), cur_level.end());
            }
            res.push_back(cur_level);
        }
        return res;
    }
    static void solution(){
        Solution solution1;
        TreeNode* root = TreeNode::buildByLevel({1, 2, 3, 4, -1, -1, 5});
        vector<vector<int>> res = solution1.zigzagLevelOrder(root);
        for(auto c: res){
            for(auto i: c){
                cout<<i<<",";
            }
            cout<<endl;
        }
    }
};