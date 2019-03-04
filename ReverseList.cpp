//
// Created by 梁栋 on 2019-02-14.
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
class Solution{
public:
    void reverseCore(ListNode* cur, ListNode** head){
        if(cur->next->next != NULL){
            reverseCore(cur->next, head);
            cur->next->next = cur;
            cur->next=NULL;
        }else{
            *head = cur->next;
            cur->next->next = cur;
            cur->next = NULL;
        }

    }
    ListNode* revserList(ListNode* head){
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }
        ListNode* res = NULL;
        reverseCore(head, &res);
        return res;
    }
};
class ReverseListTest{
public:
    static void test(){
        vector<int> nums = {0, 1, 2, 3, 4, 5};
        ListNode* headNode = new ListNode(0);
        headNode = headNode->ListNodeFromVector(nums);
        Solution solution = Solution();
        ListNode* reversed = solution.revserList(headNode);
        reversed->print();

        vector<int> nums1 = {0, 1};
        vector<int> nums2 = {0};
        headNode = headNode->ListNodeFromVector(nums1);
        reversed = solution.revserList(headNode);
        reversed->print();
        headNode = headNode->ListNodeFromVector(nums2);
        reversed = solution.revserList(headNode);
        reversed->print();


    }
};