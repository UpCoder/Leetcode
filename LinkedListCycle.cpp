//
// Created by 梁栋 on 2019-05-07.
//


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int > unordered_map1;
        while(head != NULL){
            if(unordered_map1[head] == 1)
                return true;
            else{
                unordered_map1[head] = 1;
                head = head->next;
            }
        }
        return false;
    }
    ListNode* hasCycle(ListNode* head){
        ListNode* slow = head;
        if(head == NULL)
            return NULL;
        ListNode* fast = head->next;
        while(slow != NULL && fast != NULL){
            if(slow == fast)
                return slow;
            slow = slow->next;
            fast = fast->next;
            if(fast == NULL)
                return NULL;
            fast = fast->next;
        }
        return NULL;
    }
    int lenCycle(ListNode* target){
        // 如果循环确实存在，则判断循环内一共有多少个点
        ListNode* cur = target->next;
        int len = 1;
        while(cur != target){
            cur = cur->next;
            len += 1;
        }
        return len;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* node_in_cycle = hasCycle(head);
        if(node_in_cycle == NULL)
            return NULL;
        int len_cycle = lenCycle(node_in_cycle);
        // 对于每个节点，我们计算其后的第len_cycle节点是不是该节点，如果是，则该点就是入口，返回
//        ListNode* cur = head;
//        while(true){
//            int num = len_cycle;
//            ListNode* find = cur;
//            while(num--){
//                find = find->next;
//            }
//            if(find == cur)
//                return cur;
//            cur = cur->next;
//        }
//        return NULL;
        ListNode* second = head;
        int num = len_cycle;
        while(num -- )
            second = second->next;
        // 我们可以确保第一个相遇的点就是入口
        // 可以利用反证法证明，假设相遇的不是入口，因为他们之间相差N个节点&&步调也一致，
        // 所以前一个也是相同的，所以第一个相遇的肯定是入口
        ListNode* first = cur;
        while(first != second){
            first = first->next;
            second = second->next;
        }
        return first;
    }
};