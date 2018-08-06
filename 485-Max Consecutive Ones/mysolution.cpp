class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0,tem=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i])
                tem++;
            else
                tem=0;
            if(tem>=res)
                res=tem;
        }
        
        return res;
    }
};