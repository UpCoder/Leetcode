//
// Created by 梁栋 on 2019-11-22.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums){
        int size = nums.size();
        if(size == 0)
            return 0;
        int start = 0, end = 0;
        int maxend = 0;
        int step = 0;
        while(end < size-1){
            for(int i=start;i<=end;i++){
                if((i+nums[i]) >= (size -1))
                    return step+1;
                maxend = max(maxend, i+nums[i]);// 能抵达的最远的位置
            }
            start = end;
            step += 1;
            end = maxend;
        }
        return step;
    }
    int jump2(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        int steps[size];
        for(int i=0;i<size;i++){
            steps[i] = size + 1;
        }
        steps[0] = 0;
        for(int i=0;i<size;i++){
            for(int j=1;j<=nums[i];j++){
                if((i+j) < size){
                    steps[i+j] = min(steps[i+j], steps[i] + 1);
                }
            }
        }
        for(int i=0;i<size;i++){
            cout<<steps[i]<<",";
        }
        cout<<endl;
        return steps[size-1];
    }
    static void solution(){
        Solution solution1;
        vector<int> nums = {2,3,1,1,4};
        int result = solution1.jump(nums);
        cout<<result<<endl;
    }
};