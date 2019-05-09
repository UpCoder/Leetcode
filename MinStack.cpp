//
// Created by 梁栋 on 2019-05-09.
//
#include <queue>
#include <stack>
#include <iostream>
using namespace std;
class MinStack {
private:
    stack<int> nums;
    stack<int> min_nums;
public:
    /** initialize your data structure here. */
    MinStack() {
        nums = stack<int>();
        min_nums = stack<int>();
    }

    void push(int x) {
        nums.push(x);
        if(min_nums.empty())
            min_nums.push(x);
        else
            min_nums.push(min(x, min_nums.top()));
    }

    void pop() {
        nums.pop();
        min_nums.pop();
    }

    int top() {
        return nums.top();
    }

    int getMin() {
        return min_nums.top();
    }
};
class Solution{
public:
    static void solution(){
        MinStack stack1;
        stack1.push(-2);
        stack1.push(0);
        stack1.push(-3);
        cout<<stack1.getMin()<<endl;
        stack1.pop();
        cout<<stack1.top()<<endl;
        cout<<stack1.getMin()<<endl;
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
