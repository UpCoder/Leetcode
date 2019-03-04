//
// Created by 梁栋 on 2019-02-18.
//
#include <vector>
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode* ListNodeFromVector(vector<int> xs){
        ListNode* head = this;
        for(int i=0;i<xs.size();i++){
            head->next = new ListNode(xs[i]);
            head = head->next;
        }
        return this->next;
    }
    void print(){
        ListNode* head = this;
        while(head != NULL){
            cout<<head->val<<"->";
            head = head->next;
        }
        cout<<endl;
    }
};
class BinaryTree{
private:
    ListNode* root;
    ListNode* lChild;
    ListNode* rChild;
public:
    BinaryTree(int val){
        this->root->val = val;
        this->lChild = NULL;
        this->rChild = NULL;
    }
    void insertlChild(int val){
        if(this->lChild == NULL){
            this->lChild = new ListNode(val);
        }else{
            this->lChild->val = val;
        }
    }
    void insertrChild(int val){
        if(this->rChild == NULL){
            this->rChild = new ListNode(val);
        }else{
            this->rChild->val = val;
        }
    }
};