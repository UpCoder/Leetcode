//
// Created by 梁栋 on 2019-01-14.
//
#include <iostream>
#include <vector>
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
struct cmp{
    bool operator()(ListNode* a, ListNode* b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeBinaryList(ListNode* l1, ListNode* l2){
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                res->next = new ListNode(l1->val);
                l1 = l1->next;
                res = res->next;
            }else{
                res->next = new ListNode(l2->val);
                l2 = l2->next;
                res = res->next;
            }
        }
        if(l1 != NULL){
            res->next = l1;
        }
        if(l2 != NULL){
            res->next = l2;
        }
        return head->next;
    }
    // 时间复杂度O(Nlog(k))
    ListNode* binary_divided(vector<ListNode*>& lists, int s, int e){
        if(s == e){
            return lists[s];
        }else{
            if(s < e){
                int mid = (s + e) / 2;
                ListNode* l1 = binary_divided(lists, s, mid);
                ListNode* l2 = binary_divided(lists, mid + 1, e);
                return mergeBinaryList(l1, l2);
            }else{
                return NULL;
            }
        }
    }
    // 时间复杂度O(kN)
    void generate(vector<ListNode*>& lists, ListNode* head){
        //head->print();
        ListNode** min_node = NULL;
        for(int i=0;i<lists.size();i++){
            if(lists[i] != NULL){
                if(min_node == NULL){
                    min_node = &lists[i];
                }else{
                    if((*min_node)->val > lists[i]->val){
                        min_node = &lists[i];
                    }
                }
            }else{
                continue;
            }
        }
        if(min_node == NULL){
            return ;
        }
        head->next = new ListNode((*min_node)->val);
        *min_node = (*min_node)->next;
        generate(lists, head->next);
    }
    // 时间复杂度O(Nlog(k))
    ListNode* priority_queue_method(vector<ListNode* > lists){
        priority_queue<int, vector<int >, greater<int> > queue1;
        for(int i=0;i<lists.size();i++){
            ListNode* head = lists[i];
            while(head != NULL){
                queue1.push(head->val);
                head = head->next;
            }
        }
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        while(not queue1.empty()){
            res->next = new ListNode(queue1.top());
            queue1.pop();
            res = res->next;
        }
        return head->next;

    }
    ListNode* priority_queue_method_v2(vector<ListNode* > lists){
        priority_queue<ListNode*, vector<ListNode* >, cmp> queue1;
        for(int i=0;i<lists.size();i++){
            // ListNode* head = lists[i];
            if(lists[i] != NULL)
                queue1.push(lists[i]);
        }
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        while(not queue1.empty()){
            ListNode* top = queue1.top();
            res->next = new ListNode(top->val);
            queue1.pop();
            res = res->next;
            if(top->next != NULL){
                queue1.push(top->next);
            }
        }
        return head->next;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        ListNode* head = new ListNode(0);
//        generate(lists, head);
//        return head->next;
        // return binary_divided(lists, 0, lists.size()-1);
        // return priority_queue_method(lists);
        return priority_queue_method_v2(lists);
    }
};
class MergeKSortedLists{
public:
    static void test(){
        vector<int> xs1 = {1, 4, 5};
        vector<int> xs2 = {1, 3, 4};
        vector<int> xs3 = {2, 6};
        ListNode* l1 = (new ListNode(0))->ListNodeFromVector(xs1);
        ListNode* l2 = (new ListNode(0))->ListNodeFromVector(xs2);
        ListNode* l3 = (new ListNode(0))->ListNodeFromVector(xs3);
        vector<ListNode* > ls = {l1, l2, l3};
        Solution solution = Solution();
        ListNode* res = solution.mergeKLists(ls);
        res->print();
    }
};