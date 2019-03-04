//
// Created by 梁栋 on 2019-03-04.
//

#include <iostream>
#include <vector>
using namespace std;
class UnionSet{
private:
    int n;
    int* parent;
    int* rank;
public:
    UnionSet(int n){
        this->n = n;
        this->parent = new int[this->n];
        this->rank = new int[this->n];
        for(int i=0;i<n;i++){
            this->rank[i] = 0;
            this->parent[i] = i;
        }
    }
    int countNumberofSet(){
        if(this->n == 0)
            return 0;
        int count = 0;
        bool flag[n];
        memset(flag, 0, sizeof(bool) * this->n);
        while(true){
            int index = -1;
            for(int i=0;i<this->n;i++){
                if(!flag[i]){
                    index = i;
                    break;
                }
            }
            if(index == -1)
                return count;
            int parent = this->findParent(index);
            for(int i=0;i<this->n;i++){
                if(this->findParent(i) == parent){
                    flag[i] = true;
                }
            }
            count += 1;

        }
    }
    int findParent(int x){
        if(this->parent[x] == x)
            return x;
        this->parent[x] = findParent(this->parent[x]);
        return this->parent[x];
    }

    void unite(int x, int y){
        int parent_x = findParent(x);
        int parent_y = findParent(y);
//        cout<<"x="<<x<<", parent_x="<<parent_x<<endl;
//        cout<<"y="<<y<<", parent_y="<<parent_y<<endl;
        if(x == y){
            return;
        }
        if(rank[parent_x] > rank[parent_y]){
            this->parent[parent_y] = parent_x;
        }else{
            this->parent[parent_x] = parent_y;
            if(rank[parent_x] == rank[parent_y]){
                rank[parent_x] += 1;
            }
        }
        parent_x = findParent(x);
        parent_y = findParent(y);
//        cout<<"x="<<x<<", parent_x="<<parent_x<<endl;
//        cout<<"y="<<y<<", parent_y="<<parent_y<<endl;
    }

    bool atSameSet(int x, int y){
        return this->findParent(x) == this->findParent(y);
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        UnionSet unionSet(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(M[i][j] == 1){
                    unionSet.unite(i, j);
                }
            }
        }
        return unionSet.countNumberofSet();

    }
};
class FriendCircles{
public:

    static void test(){
        vector<vector<int > > M = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
        Solution solution;
        cout<<solution.findCircleNum(M)<<endl;
    }
};