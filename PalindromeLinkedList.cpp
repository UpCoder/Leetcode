//
// Created by 梁栋 on 2019-05-16.
//
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    static ListNode* ListNodeFromVector(vector<int> xs){
        ListNode* head = new ListNode(0);
        ListNode* first = head;
        for(int i=0;i<xs.size();i++){
            head->next = new ListNode(xs[i]);
            head = head->next;
        }
        return first->next;
    }
    void print(){
        ListNode* head = this;
        while(head){
            cout<<head->val<<"->";
            head = head->next;
        }
        cout<<endl;
    }
};
class Solution {
public:
    ListNode* tmp;
    bool isPalindrome(ListNode* head) {
        // 判断list是否是回文list
        tmp = head;
        return check(head);
    }
    bool check(ListNode* head){
        if(head == NULL)
            return true;
        if(check(head->next) && head->val == tmp->val){
            tmp = tmp->next;
            return true;
        }
        return false;
    }
    bool isPalindromeV2(ListNode* head){
        if(head == NULL)
            return true;
        ListNode* dump = new ListNode(0);
        dump->next = head;
        ListNode* slow = dump;
        ListNode* fast = dump;
        while(slow->next && fast->next){
            fast = fast->next;
            if(fast->next){
                fast = fast->next;
                slow = slow->next;
            }
        }
        ListNode* last2 = NULL;
        ListNode* start2 = slow->next;
        while(last2 != fast){
            ListNode* tmp = start2->next;
            start2->next = last2;
            last2 = start2;
            start2 = tmp;
        }
        slow->next = NULL;
        slow = head;
        while(slow && fast){
            if(slow->val == fast->val)
            {
                slow = slow->next;
                fast = fast->next;
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
    static void solution(){
        ListNode* head = ListNode::ListNodeFromVector({});
        Solution solution1;
        cout<<solution1.isPalindromeV2(head)<<endl;
    }
};