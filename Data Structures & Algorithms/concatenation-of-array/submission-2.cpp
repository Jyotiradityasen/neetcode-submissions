class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums.size()*2);
        int k=nums.size();
        for(int i=0;i<nums.size();i++)
        { 
            ans[i]=nums[i];
            ans[k++]=nums[i];
        }
        return ans;
    }
};