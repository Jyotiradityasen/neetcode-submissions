class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0 , cnt=0;
        for(int num:nums)
        {
            cnt= num? cnt+1 : 0;
            res=max(cnt,res);
        }
        return res;
    }
};