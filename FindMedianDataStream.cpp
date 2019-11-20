//
// Created by Liang on 2019-07-27.
//
#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;
class MedianFinder {
private:
//    priority_queue<int, vector<int>, greater<int>> high; // 保存较大的那一部分，升序排列
//    priority_queue<int, vector<int>, less<int> > low; // 保存较小的一部分，降序牌理 两者的size 大小不能超过1
    // vector<int> nums;
    multiset<int> avl;
    multiset<int>::iterator l_it, r_it;
public:
    /** initialize your data structure here. */
    MedianFinder() {
//        high = priority_queue<int, vector<int>, greater<int> >();
//        low = priority_queue<int, vector<int>, less<int> >();
        // nums = vector<int>();
        avl = multiset<int>();
    }

    void addNum(int num) {
        const int n = avl.size();
        avl.insert(num);
        if(n == 0){
            l_it = r_it = avl.begin();
        }else{
            if(n & 1){
                // 奇数
                if(num < (*l_it)){
                    l_it--;
                }else{
                    r_it ++;
                }
            }else{
                // 偶数
                if(num>(*l_it) && num<(*r_it)){
                    l_it++;
                    r_it--;
                }else{
                    if(num >= (*r_it)){
                        l_it++;
                        r_it = l_it;
                    }else{
                        r_it --;
                        l_it = r_it;

                    }
                }
            }
        }

    }

    double findMedian() {
        return ((*l_it) + (*r_it)) * 0.5;
    }
};
class Solution{
public:
    static void solution(){
        MedianFinder finder;
        finder.addNum(6);
        cout<<finder.findMedian()<<endl;
        finder.addNum(10);
        cout<<finder.findMedian()<<endl;
        finder.addNum(2);
        cout<<finder.findMedian()<<endl;
        finder.addNum(6);
        cout<<finder.findMedian()<<endl;
        finder.addNum(5);
        cout<<finder.findMedian()<<endl;
        finder.addNum(0);
        cout<<finder.findMedian()<<endl;
        finder.addNum(6);
        cout<<finder.findMedian()<<endl;
        finder.addNum(3);
        cout<<finder.findMedian()<<endl;
        finder.addNum(1);
        cout<<finder.findMedian()<<endl;
        finder.addNum(0);
        cout<<finder.findMedian()<<endl;
        finder.addNum(0);
        cout<<finder.findMedian()<<endl;
    }
};