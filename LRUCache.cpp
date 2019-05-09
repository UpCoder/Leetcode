//
// Created by 梁栋 on 2019-05-09.
//
#include <iostream>
#include <unordered_map>
using namespace std;
class DLinkNode{
    // 双向链表
public:
    int val;
    int k;
    DLinkNode* pre;
    DLinkNode* next;
    DLinkNode(){
        pre = NULL;
        next = NULL;
        val = 0;
    }
    DLinkNode(int v){
        val = v;
        pre = NULL;
        next = NULL;
    }
    void add(DLinkNode* added){
        // 在该点后加入一个新的点
        added->pre = this;
        added->next = this->next;

        this->next->pre = added;
        this->next = added;
    }
    void remove(){
        // 从list中移出该点
        this->pre->next = this->next;
        this->next->pre = this->pre;
    }
    static void moveToHead(DLinkNode* head, DLinkNode* node){
        node->remove(); // 从list中删除该点
        head->add(node); // 将该点移动到head后
    }
};
class LRUCache {
private:
    unordered_map<int, DLinkNode*> dict;
    int count = 0;
    int capacity = 0;
    DLinkNode* head;
    DLinkNode* tail;
public:
    LRUCache(int capacity) {
        count = 0;
        this->capacity = capacity;
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->pre = head;
    }
    int get(int key) {
        DLinkNode* res = dict[key];
        if(res == NULL)
            return -1;// not found
        DLinkNode::moveToHead(head, res);   // 移动到最前面
        return res->val;
    }

    void put(int key, int value) {
        DLinkNode* res = dict[key];
        if(res == NULL){
            count += 1;
            DLinkNode* newNode = new DLinkNode(value);
            newNode->k = key;
            head->add(newNode);
            dict[key] = newNode;
            if(count > capacity){
                dict[tail->pre->k] = NULL;
                tail->pre->remove(); //删除该点
                count --;
            }
        }else{
            res->val = value;
            DLinkNode::moveToHead(head, res);   // 移动到最前面
        }
    }
};
class Solution{
public:
    static void solution(){
        LRUCache cache(2);
        cache.put(2, 1);
        cache.put(2, 2);
        cout<<cache.get(2)<<endl;       // returns 1
        cache.put(3, 3);    // evicts key 2
        cout<<cache.get(2)<<endl;       // returns -1 (not found)
        cache.put(4, 4);    // evicts key 1
        cout<<cache.get(1)<<endl;       // returns -1 (not found)
        cout<<cache.get(3)<<endl;       // returns 3
        cout<<cache.get(4)<<endl;       // returns 4
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
