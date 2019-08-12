//
// Created by Liang on 2019-07-10.
//

#include <vector>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;
struct Task{
    int num;
    char name;
    Task(int x, char y){
        num = x;
        name = y;
    }
    bool operator < (const Task& a) const {
        if(num < a.num)
            return true;
        return false;
    }
    bool operator > (const Task& a) const{
        if(num > a.num)
            return true;
        return false;
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<Task, vector<Task>> queue1;
        unordered_map<char, int > count_dict;
        for(auto c: tasks){
            count_dict[c] += 1;
        }
        unordered_map<char, int>::iterator it = count_dict.begin();
        while(it != count_dict.end()){
            queue1.push(Task(it->second, it->first));
            it++;
        }
        queue<Task> tmp_queue;
        int res = 0;
        n += 1;
        while(queue1.size() >0 || tmp_queue.size() > 0){
            // 开始新一轮执行，执行n个任务
            int count = 0;
            while(count < n){
                if(queue1.size() == 0){
                    break;
                }
                Task tmp = queue1.top();
                tmp.num -= 1;
                if(tmp.num > 0)
                    tmp_queue.push(tmp);
                queue1.pop();
                res += 1;
                count += 1;
            }
            if(count != n){
                if(tmp_queue.size() > 0){
                    res += (n - count);
                    while(tmp_queue.size() > 0){
                        queue1.push(tmp_queue.front());
                        tmp_queue.pop();
                    }
                }else{
                    break;
                }
            }else{
                while(tmp_queue.size() > 0){
                    queue1.push(tmp_queue.front());
                    tmp_queue.pop();
                }
            }
        }
        return res;
    }
    static void solution(){
        Solution solution1;
        vector<char > tasks = {'A','A','A','B','B','B'};
        int n = 2;
        cout<<solution1.leastInterval(tasks, n)<<endl;
    }
};