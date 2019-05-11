//
// Created by 梁栋 on 2019-05-11.
//
#include <vector>
#include <iostream>
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || head->next == NULL)
            return head;
        if(m == n)
            return head;
        ListNode* dump = new ListNode(0);
        dump->next = head;
        ListNode* last = dump;
        ListNode* cur = head;
        m -= 1;
        n -= 1;
        ListNode* ll;
        ListNode* lr;
        ListNode* rl;
        ListNode* rr;
        int idx = 0;
        while(cur){
            if(idx > n)
                break;
            if(idx == m){
                ll = last;
                lr = cur;
            }
            if(idx == n){
                rl = cur;
                rr = cur->next;
            }
            if(idx > m && idx <= n){
                ListNode* newCur = cur->next;
                cur->next = last;
                last = cur;
                cur = newCur;
            }else{
                last = cur;
                cur = cur->next;
            }
            idx += 1;
        }
        ll->next = rl;
        lr->next = rr;
        return dump->next;
    }
    static void solution(){
        Solution solution1;
        ListNode* head = ListNode::ListNodeFromVector({1, 2, 3, 4, 5});
        ListNode* res = solution1.reverseBetween(head, 1, 5);
        res->print();
    }
};