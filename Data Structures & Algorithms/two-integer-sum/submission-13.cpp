class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            int reach=target-nums[i];
            if(mp.find(reach)!=mp.end())
            {
                return {mp[reach],i};
            }
            mp[nums[i]]=i;
        }
        return{};
    }
};
