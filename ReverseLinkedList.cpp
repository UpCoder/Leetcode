//
// Created by 梁栋 on 2019-05-10.
//
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseListRecursively(ListNode* head, ListNode*& lastNode){
        if(head->next == NULL){
            lastNode = head;
            return head;
        }
        ListNode* next = reverseListRecursively(head->next);
        next->next = head;
        head->next = NULL;
        return head;
    }
    ListNode* reverseListIteratively(ListNode* head){
        ListNode* cur = head->next;
        ListNode* last = head;
        head->next = NULL;
        while(cur){
            ListNode* newCur = cur->next;
            cur->next = last;
            last = cur;
            cur = newCur;
        }
        return last;
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
//        ListNode* newHead(0);
//        reverseListRecursively(head, newHead);
//        return newHead;
        return reverseListIteratively(head);
    }
};