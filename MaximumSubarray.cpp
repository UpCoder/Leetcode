//
// Created by 梁栋 on 2019-03-20.
//
class Solution{
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int res = nums[0];
        for(int i=0;i<nums.size();i++){
            if(sum<=0){
                sum = nums[i];
                res = max(res, sum);
                continue;
            }else{
                sum += nums[i];
                res = max(res, sum);
            }
        }
        return res;
    }
};
class MaximumSubarray{
public:
    static void test(){
        Solution solution;
        vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
        cout<<solution.maxSubArray(nums)<<endl;
    }
};

