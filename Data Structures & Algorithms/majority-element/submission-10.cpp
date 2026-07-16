class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num=nums[0];
        int count=0;
        for(int a:nums){
            if(count==0){
                num=a;
                count++;
            }
            if(a!=num)count--;
            if(a==num)count++;


        }
        int countf;
        for(int a: nums){
            if(a==num)countf++;
        }
        if(countf>nums.size()/2)return num;
        else return -1;

    }
};