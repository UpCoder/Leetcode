//
// Created by 梁栋 on 2019-01-13.
//


// Definition for singly-linked list.
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode** p = &l1;
        ListNode** q = &l2;
        while((*q) != NULL){
            while((*p) != NULL && (*p)->val <= (*q)->val){
                p = &((*p)->next);
            }
            swap(*p, *q);
        }
        return l1;
    }

    ListNode* mergeTwoLists_v1(ListNode* l1, ListNode* l2) {
        ListNode* node = new ListNode(0);
        ListNode* res = node;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                node->next = new ListNode(l1->val);
                l1 = l1->next;
            }else{
                node->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            node = node->next;
        }
        if(l1 != NULL){
            node->next = l1;
        }
        if(l2 != NULL){
            node->next = l2;
        }
        return res->next;
    }
};