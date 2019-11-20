//
// Created by Liang on 2019-07-02.
//
#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    double findSolution(const double* data, int source, int size, int target_y, double res, bool* visit){
        if(source == target_y){
            return res;
        }
        for(int i=0;i<size;i++){
            // cout<<"find idx is "<<source * size + i<<" , "<<data[source * size + i]<<" , "<<visit[source * size + i]<<endl;
            if(data[source * size + i] != -1. && visit[source * size + i]){
                visit[source * size + i] = false;
                double tmp = findSolution(data, i, size, target_y, res * data[source * size + i], visit);
                if(tmp != -1.0){
                    return tmp;
                }
                visit[source * size + i] = true;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, int> exisits;
        int size = equations.size();


        int count = 1;  // 统计一共有多少个不同的字符串
        for(int i=0;i<size;i++){
            vector<string> tmp = equations[i];
            double v = values[i];
            string first = tmp[0];
            string second = tmp[1];
            if(exisits[first] == 0){
                exisits[first] = count;
                count += 1;
            }
            if(exisits[second] == 0){
                exisits[second] = count;
                count += 1;
            }

        }
        double data[count * count];
        for(int i=0;i<count*count;i++)
            data[i] = -1.;
        for(int i=0;i<size;i++){
            vector<string> tmp = equations[i];
            double v = values[i];
            string first = tmp[0];
            string second = tmp[1];
            int idx = exisits[first] * count + exisits[second];
            //cout<<idx<<" "<<v<<endl;
            data[idx] = v;
            if(v != 0){
                idx = exisits[second] * count + exisits[first];
                data[idx] = 1. / v;
            }
        }
        vector<double > res;
        for(auto ele: queries){
            string first = ele[0];
            string second = ele[1];
            int target_x = exisits[first];
            int target_y = exisits[second];
            //cout<<"target_x "<<target_x<<", target_y "<<target_y<<endl;
            if(target_x == 0 or target_y == 0){
                res.push_back(-1.0);
                continue;
            }
            bool visits[count * count];
            memset(visits, 1, sizeof(visits));

            res.push_back(findSolution(data, target_x, count, target_y, 1.0, visits));
        }
        return res;
    }
    static void solution(){
        Solution solution1;
        vector<vector<string>> equations = {
                {"a", "b"},
                {"b", "c"}
        };
        vector<double > values = {2., 3.};
        vector<vector<string>> queries = {
                {"a", "c"},
                {"b", "a"},
                {"a", "e"},
                {"a", "a"},
                {"x", "x"}
        };
        vector<double > res = solution1.calcEquation(equations, values, queries);
        for(auto e: res){
            cout<<e<<", ";
        }
        cout<<endl;
    }
};