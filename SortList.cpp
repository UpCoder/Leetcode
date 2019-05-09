//
// Created by 梁栋 on 2019-05-08.
//
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(vector<int> nums){
        this->val = nums[0];
        ListNode* cur = this;
        for(int i=1;i<nums.size();i++){
            cur->next = new ListNode(nums[i]);
            cur = cur->next;
        }
    }
    void print(){
        ListNode* cur = this;
        while(cur){
            cout<<cur->val<<"->";
            cur = cur->next;
        }
        cout<<endl;
    }
};

class Solution {
public:
    static void solution(){
        Solution solution1;
        ListNode* head = new ListNode({5, 3, 2, 4, 1});
        head = solution1.sortList(head);
        head->print();
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        int len = 0; // 得到链表的长度
        ListNode* cur = head;
        while (cur){
            cur = cur->next;
            len += 1;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prior;
        for(int step=1;step<len;step <<= 1){
            // step 代表的是每个ele的长度，一开始都是1，每次乘以2
            ListNode* cur = dummy->next;
            prior = dummy;
            while(cur){
                ListNode* first = cur;
                ListNode* second = split(first, step);
                cur = split(second, step);
                prior = merge(first, second, prior);
            }
        }
        return dummy->next;
    }
private:
    ListNode* split(ListNode* head, int n){
        // 截取从head开始的n个节点，去到第n个时候next等于NULL，并且返回下一个stage开始的节点
        for(int i=0;i<(n-1) && head;i++)
            head = head->next;
        if(head == NULL)
            return NULL;
        ListNode* second = head->next;
        head->next = NULL; // 代表本段的结束
        return second;
    }
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* prior){
        // l1 第一stage的起点，l2第二stage的起点，cur 总的起点
        while(l1 && l2){
            if(l1->val < l2->val){
                prior->next = l1;
                l1 = l1->next;
                prior = prior->next;
            }else{
                prior->next = l2;
                l2 = l2->next;
                prior = prior->next;
            }
        }
        if(l1)
            prior->next = l1;
        if(l2)
            prior->next = l2;
        while (prior->next){
            prior = prior->next;
        }
        return prior;
    }
};