//
// Created by 梁栋 on 2019-01-06.
//
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        string res = "";
        for(int i=1;i<=numRows;i++)
        {

            int pos = i - 1;
            if(i==1){
                int cur_interval = 2 * numRows - 2 - 2 * (i-1);
                while(pos < s.length()){
                    res += s[pos];
                    pos += cur_interval;
                }
            }
            if(i == numRows){
                int cur_interval = 2 * numRows - 2;
                while(pos < s.length()){
                    res += s[pos];
                    pos += cur_interval;

                }
            }
            // 既不是第一行也不是最后一行
            int cur_interval = 2 * numRows - 2 - 2 * (i-1);
            while(pos < s.length()){
                res += s[pos];
                int mid_pos = pos + cur_interval;
                if(mid_pos < s.length()){
                    res += s[mid_pos];
                }
                pos += (2 * numRows - 2);
            }

        }
        return res;
    }
};

class ZigZagConversion {
public:
    void static test(){
        string s = "PAYPALISHIRING";
        int numRows = 4;
        Solution solution = Solution();
        string res = solution.convert(s, numRows);
        cout<<res<<endl;
        //PINALSIGYAHRPI
        //PINALSIGYAHRPI
    }
};