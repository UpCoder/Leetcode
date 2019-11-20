//
// Created by Liang on 2019-08-11.
//
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(){}
    Node(int x) : val(x), left(NULL), right(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
    static Node* buildByLevel(vector<int> nums){
        Node* root = new Node(nums[0], NULL, NULL, NULL);

        queue<Node* > queue1;
        int null_target = -1;
        queue1.push(root);
        for(int i=1;i<nums.size();i+=2){
            int lchild = nums[i];
            int rchild = nums[i+1];
            Node* cur = queue1.front();
            queue1.pop();
            if(lchild != null_target){
                cur->left = new Node(lchild);
                queue1.push(cur->left);
            }
            else
                cur->left= NULL;
            if(rchild != null_target){
                cur->right = new Node(rchild);
                queue1.push(cur->right);
            }
            else
                cur->right = NULL;
        }
        return root;
    }
    static void levelOrder(Node* root) {
        vector<vector<int>> res;
        vector<int> cur_level;
        int nums = 1;
        int count = 0;
        queue<Node*> nodes;
        nodes.push(root);
        int next_levels_num = 0;

        while(!nodes.empty()){
            Node* cur_node = nodes.front();
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
    Node* cloneNode(Node* root){
        if(root == NULL)
            return NULL;
        Node* res = new Node(root->val);
        res->left = cloneNode(root->left);
        res->right = cloneNode(root->right);
        return res;
    }
    Node* connect(Node* root) {
        if(root == NULL)
            return NULL;
        queue<Node* > nodes;
        Node* res = cloneNode(root);
        nodes.push(res);
        while(!nodes.empty()){
            int cur_size = nodes.size();
            Node* last = NULL;
            for(int i=0;i<cur_size;i++){
                Node* cur_node = nodes.front();
                nodes.pop();
                if(last != NULL){
                    last->next = cur_node;
                }
                last = cur_node;
                if(cur_node->left){
                    nodes.push(cur_node->left);
                }
                if(cur_node->right){
                    nodes.push(cur_node->right);
                }
            }
        }
        return res;
    }
    Node* connectV2(Node* root){
        if(root == NULL)
            return NULL;
        Node* left = root->left;
        Node* right = root->right;
        while(left){
            left->next = right;
            left = left->right;
            right = right->left;
        }
        connectV2(root->left);
        connectV2(root->right);
        return root;
    }
    static void solution(){
        Node* root = Node::buildByLevel({1, 2, 3, 4, 5, 6, 7});
        Solution solution1;
        Node* res = solution1.connect(root);
        Node::levelOrder(res);
    }
};