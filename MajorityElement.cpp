//
// Created by 梁栋 on 2019-05-09.
//

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int lastNum = nums[0];
        int count = 1;
        for(int i=1;i<nums.size();i++){
            if(lastNum == nums[i]){
                count += 1;
            }else{
                count -= 1;
                if(count == 0){
                    count = 1;
                    lastNum = nums[i];
                }
            }
        }
        return lastNum;
    }
};