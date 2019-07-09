//
// Created by Liang on 2019-07-07.
//
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
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
    unordered_map<int, int> shown; // 判断路径上从root到某点的sum是否出现过
    int exisitSolution(vector<int> paths, int cur_ele, int sum){
        int res = 0;
        for(int i=paths.size()-1;i>=0;i--){
            cur_ele += paths[i];
            if(cur_ele == sum)
                res += 1;
        }
        return res;
    }
    int pathSumCore(TreeNode* root, int sum, vector<int> paths){
        // 必须包含paths里面的最后一个元素
        if(root == NULL)
            return 0;
        int cur = exisitSolution(paths, root->val, sum);
        if(root->val == sum){
            cur += 1;
        }
        paths.push_back(root->val);
        int left = pathSumCore(root->left, sum, paths);
        int right = pathSumCore(root->right, sum, paths);
        return left + right + cur;
    }
    int pathSumCoreV2(TreeNode* root, int sum, int pre_sum){
        if(root == NULL)
            return 0;
        pre_sum += root->val; // 包含当前节点从root到当前节点的sum
        int cur = shown[pre_sum - sum]; // 存在某种节点的个数，从根节点到该节点的和为pre_sum - sum, 则从当前节点到该节点的和就为sum
        shown[pre_sum] = shown[pre_sum] + 1; // 和为pre sum的节点个数加一
        int left = pathSumCoreV2(root->left, sum, pre_sum);
        int right = pathSumCoreV2(root->right, sum, pre_sum);
        shown[pre_sum] -= 1;    // 因为只能是单边的，所以这里需要减1
        return cur + left + right;
    }
    int pathSum(TreeNode* root, int sum) {
        shown[0] = 1;
        return pathSumCoreV2(root, sum, 0);
//        vector<int> paths;
//        if(root == NULL)
//            return 0;
//        paths.push_back(root->val);
//        int cur = (root->val == sum);
//        int left = pathSumCore(root->left, sum, paths);
//        int right = pathSumCore(root->right, sum, paths);
//        return left + right + cur;
    }
    static void solution(){
        Solution solution1;
        TreeNode* root = TreeNode::buildByLevel({1,0,1,1,2,0,-1,0,1,-1,0,-1,0,1,0}, -5);
        TreeNode::levelOrder(root);
        cout<<solution1.pathSum(root, 2)<<endl;
    }
};