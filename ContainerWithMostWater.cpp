//
// Created by 梁栋 on 2019-01-10.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int res = 0;
        int r=0;
        int l=size-1;
        while(r < l){
            int area = (l-r) * min(height[l], height[r]);
            if(height[l] < height[r]){
                l -= 1;
            }
            else{
                r += 1;
            }

            res = max(res, area);
        }

        return res;
    }
    int maxArea_v1(vector<int>& height) {
        int size = height.size();
        int res = 0;
        for(int i=0;i<size;i++){
            for(int j=i+1; j<size;j++){
                int area = (j-i) * min(height[i], height[j]);
                res = max(res, area);
            }
        }
        return res;
    }
};
class ContainWithMostWater {
public:
    static void test(){
        vector<int > height = {1,8,6,2,5,4,8,3,7};
        Solution solution = Solution();
        cout<<solution.maxArea(height)<<endl;
    }
};
