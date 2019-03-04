//
// Created by 梁栋 on 2018-12-16.
//
#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int init_val = l1->val + l2->val;
        bool added_flag = false;
        if(init_val >= 10){
            init_val -= 10;
            added_flag = true;
        }
        ListNode* listNode = new ListNode(init_val);
        ListNode* header = listNode;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 != NULL or l2 != NULL){
            int cur_val = 0;
            if(l1 != NULL){
                cur_val += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                cur_val += l2->val;
                l2 = l2->next;
            }
            if(added_flag){
                cur_val += 1;
                added_flag = false;
            }
            if(cur_val >= 10){
                cur_val -= 10;
                added_flag = true;
            }
            listNode->next = new ListNode(cur_val);
            listNode = listNode->next;
        }
        if(added_flag){
            int cur_val = 1;
            listNode->next = new ListNode(cur_val);
        }
        return header;
    }
};
class AddTwoNumber {
public:
    static void test(){

    }
};
