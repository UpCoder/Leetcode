//
// Created by 梁栋 on 2019-05-09.
//
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* first = headA;
        ListNode* second = headB;
        while(first && second){
            first = first->next;
            second = second->next;
        }
        while(first){
            first = first->next;
            headA = headA->next;
        }
        while(second){
            second = second->next;
            headB = headB->next;
        }
        while(headA && headB){
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};