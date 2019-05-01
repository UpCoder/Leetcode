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
    vector<vector<int>> levelOrder(TreeNode* root) {
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
        return res;
    }
public:
    TreeNode* buildTreeBase(vector<int>& preorder, vector<int>& inorder,
            int l_pre, int r_pre, int l_in, int r_in){
        if(l_pre > r_pre || l_in > r_in){
            return NULL;
        }
        int root_value = preorder[l_pre];
        TreeNode* root = new TreeNode(root_value);
        int target_l_in = -1;
        for(int i=l_in; i<=r_in;i++){
            if(inorder[i] == root_value){
                target_l_in = i;
                break;
            }
        }
        int num_nodes_left = target_l_in - l_in;
        root->left = buildTreeBase(preorder, inorder, l_pre + 1, l_pre + num_nodes_left ,l_in, target_l_in-1);
        root->right = buildTreeBase(preorder, inorder, l_pre + num_nodes_left + 1, r_pre, target_l_in + 1, r_in);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() != inorder.size())
            return NULL;
        int size = (int) preorder.size();
        return buildTreeBase(preorder, inorder, 0, size-1, 0, size-1);
    }
    static void solution(){
        vector<int> preorder = {3, 9, 20, 15, 7};
        vector<int> inorder = {9, 3, 15, 20, 7};
        Solution solution1;
        TreeNode* root = solution1.buildTree(preorder, inorder);
        vector<vector<int>> res = solution1.levelOrder(root);
        for(auto v: res){
            for(auto e: v){
                cout<<e<<", ";
            }
            cout<<endl;
        }
    }
};