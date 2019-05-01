//
// Created by 梁栋 on 2019-04-30.
//
#include <iostream>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        int counts[n+1];
        counts[0] = 1;
        counts[1] = 1;
        counts[2] = 2;
        if(n<=2)
            return counts[n];
        for(int i=3;i<=n;i++){
            int count = 0;
            // 一共是i个点
            for(int j=0;j<i;j++){
                // 选取第j点作为根节点
                count += (counts[j] * counts[i-j-1]);
            }
            counts[i] = count;
        }
        return counts[n];
    }
    static void solution(){
        Solution solution1;
        cout<<solution1.numTrees(0)<<endl;
        cout<<solution1.numTrees(1)<<endl;
        cout<<solution1.numTrees(2)<<endl;
        cout<<solution1.numTrees(3)<<endl;
        cout<<solution1.numTrees(4)<<endl;
    }
};