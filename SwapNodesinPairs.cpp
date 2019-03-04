//
// Created by 梁栋 on 2019-01-14.
//
#include <iostream>
#include <vector>
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
class Solution {
public:
    void generate(ListNode* head){
        if(head!=NULL && head->next != NULL){
            int tmp = head->val;
            head->val = head->next->val;
            head->next->val = tmp;
            generate(head->next->next);
        }else{
            return;
        }
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode* res = head;
        generate(head);
        return res;
    }
    ListNode* swapPairs_v2(ListNode* head) {
        ListNode** pp = &head;
        ListNode *a, *b;
        while((a = *pp) && (b = a->next)){
            a->next = b->next;
            b->next = a;
            *pp = b;
            pp = &(a->next);
        }
        return head;
    }
};
class SwapNodesinPairs{
public:
    static void test(){
        vector<int> xs = {1, 2, 3, 4};
        ListNode* l1 = (new ListNode(0))->ListNodeFromVector(xs);
        l1->print();
        Solution solution = Solution();
        solution.swapPairs_v2(l1)->print();
        solution.swapPairs(l1)->print();

    }
};