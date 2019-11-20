//
// Created by Liang on 2019-08-23.
//
#include <iostream>
#include <cstring>
#include <string>
#include <map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
    Node(int x){val = x;next=NULL;random=NULL;}
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mapping;
        Node* first = head;
        Node* res_head = new Node(0, NULL, NULL);
        Node* copy_head = res_head;
        while(first != NULL){
            copy_head->next = new Node(first->val, NULL, NULL);
            mapping[first] = copy_head->next;
            first = first->next;
            copy_head = copy_head->next;
        }
        first = head;
        copy_head = res_head->next;
        while(first != NULL){
            if(first->random == NULL){
                first = first->next;
                copy_head = copy_head->next;
                continue;
            }
            copy_head->random = mapping[first->random];
            first = first->next;
            copy_head = copy_head->next;
        }
        return res_head->next;
    }
    static void solution(){
        Node* head = new Node(0);
        head->next = new Node(2);
        head->random=head->next;

        Solution solution1;
        Node* res_node = solution1.copyRandomList(head);
        while(res_node != NULL){
            cout<<res_node->val<<"->";
            res_node = res_node->next;
        }
        cout<<endl;

    }
};