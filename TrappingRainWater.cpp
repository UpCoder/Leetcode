//
// Created by 梁栋 on 2019-03-18.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // 时间复杂度 N^2, 空间复杂度1
//        if(height.empty())
//            return 0;
//        int res = 0;
//        for(int i=1;i<height.size()-1;i++){
//            int max_left=0;
//            int max_right=0;
//            for(int j=0;j<=i;j++){
//                max_left = max(max_left, height[j]);
//            }
//            for(int j=i;j<height.size();j++){
//                max_right = max(max_right, height[j]);
//            }
//            res += (min(max_left, max_right) - height[i]);
//        }
//        return res;
        if(height.empty()){
            return 0;
        }
//        int size = int(height.size());
//        int max_right[size];
//        int max_left[size];
//        max_right[0] = height[0];
//        for(int i=1;i<size;i++){
//            max_right[i] = max(max_right[i-1], height[i]);
//        }
//        max_left[size-1] = height[size-1];
//        for(int i=size-2;i>=0;i--){
//            max_left[i] = max(max_left[i+1], height[i]);
//        }
//        int res = 0;
//        for(int i=1;i<size-1;i++){
//            res += min(max_left[i], max_right[i]) - height[i];
//        }
//        return res;
        int left = 0;
        int size = int(height.size());
        int right = size-1;
        int max_left = 0;
        int max_right = 0;
        int res = 0;
        while (left < right){
            if(height[left] < height[right]){
                height[left] >= max_left ? (max_left = height[left]) : (res += (max_left - height[left]));
                left += 1;
            }else{
                height[right] >= max_right ? (max_right = height[right]) : (res += (max_right - height[right]));
                right -= 1;
            }
        }
        return res;

    }
};
class TrappingRainWater{
public:
    static void test(){
        vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
        // vector<int> heights = {2,0,2};
        // vector<int> heights = {4, 2, 3};
        Solution solution1;
        cout<<solution1.trap(heights)<<endl;
    }
};