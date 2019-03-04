//
// Created by 梁栋 on 2019-01-14.
//
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
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
    ListNode* reverseKGroup_v2(ListNode* head, int k){
        ListNode *res = new ListNode(0);
        ListNode *front_head = res;
        res->next = head;
        // front_head->next = head;
        ListNode* l = head;
        ListNode* r = head;

        while(true){
            // res->next->print();
            int count = 0;
            while(count<k && r != NULL){
                r = r->next;
                count += 1;
            }
            // cout<<"r is "<<r->val<<endl;
            if(count == k){
                ListNode* pre = r;
                ListNode* cur = l;
                for(int i=0;i<count;i++){
                    ListNode* second = cur->next;
                    cur->next = pre;
                    ListNode* original_cur = cur;
                    cur = second;
                    pre = original_cur;
                }
                front_head->next = pre;
                front_head = l;
                l = r;

            }else{
                // 结束了
                return res->next;
            }
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        queue<int > xs;
        while(head != NULL){
            xs.push(head->val);
            head = head->next;
        }
        ListNode* tmp = new ListNode(0);
        ListNode* res = tmp;
        while(xs.size() >= k){
            stack<int> xs_stack;
            for(int i=0;i<k;i++){
                xs_stack.push(xs.front());
                xs.pop();
            }
            while(not xs_stack.empty()){
                tmp->next = new ListNode(xs_stack.top());
                xs_stack.pop();
                tmp = tmp->next;
            }
        }
        while(not xs.empty()){
            tmp->next = new ListNode(xs.front());
            xs.pop();
            tmp = tmp->next;
        }
        return res->next;
    }
};
class ReverseNodesinK_Group{
public:
    static void test(){
        vector<int> xs = {1, 2, 3, 4, 5, 6, 7, 8};
        ListNode* l1 = (new ListNode(0))->ListNodeFromVector(xs);
        l1->print();
        Solution solution = Solution();
        solution.reverseKGroup(l1, 3)->print();
        solution.reverseKGroup(l1, 3)->print();
        ListNode* res = solution.reverseKGroup_v2(l1, 3);
        res->print();
        solution.reverseKGroup_v2(res, 3)->print();
    }
};