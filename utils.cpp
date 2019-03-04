//
// Created by 梁栋 on 2018-12-16.
//
#include <vector>
#include <iostream>
using namespace std;

class Utils{
public:
    static void print_vector(const vector<int>& x){
        unsigned long size = x.size();
        for(int i=0; i<size; i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
};