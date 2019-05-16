//
// Created by 梁栋 on 2019-05-16.
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
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path){
        if(root == NULL){
            return false;
        }
        if(root == target){
            path.push_back(root);
            return true;
        }
        bool left_res = findPath(root->left, target, path);
        if(left_res){
            path.push_back(root);
            return true;
        }
        bool right_res = findPath(root->right, target, path);
        if(right_res){
            path.push_back(root);
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        vector<TreeNode*> path_p, path_q;
        findPath(root, p, path_p);
        findPath(root, q, path_q);
        if(path_p.empty() || path_q.empty())
            return NULL;
        int size_p = (int) path_p.size();
        int size_q = (int) path_q.size();
        int start_p = 0;
        int start_q = 0;
        if(size_p >= size_q){
            start_p = size_p - size_q;
        }else{
            start_q = size_q - size_p;
        }
        for(;start_p < size_p && start_q < size_q;start_p++, start_q++){
            if(path_p[start_p] == path_q[start_q])
                return path_p[start_p];
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestorV2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestorV2(root->left, p, q); // 在左孩子中找寻找q或者p
        TreeNode* right = lowestCommonAncestorV2(root->right, p, q); // 在右子树中尝试寻找p或者q
        // 如果左孩子找到了，右孩子没找打，则是左孩子
        // 如果两个都找到了，则是root
        return left == NULL ? right: right == NULL ? left : root;
        // return !left ? right : !right ? left : root;
    }
    static void solution(){
        Solution solution1;
        TreeNode* root = TreeNode::buildByLevel({3,5,1,6,2,0,8,0,0,7,4});
        cout<<solution1.lowestCommonAncestorV2(root, root->right, root->left)->val<<endl;
    }
};